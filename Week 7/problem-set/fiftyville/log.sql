-- Keep a log of any SQL queries you execute as you solve the mystery.

-- To see information about the crime scene
SELECT description FROM crime_scene_reports 
WHERE street = 'Humphrey Street' AND
day = 28 AND
month = 7 AND
year = 2024;
-- The crime happened at 10:15am

-- To get the interviews
SELECT * FROM interviews
WHERE month = 7 AND
day = 28 AND
year = 2024 AND
transcript LIKE '%bakery%';
-- From Raymond transcript I discovered that the flight was on next day, 29

-- To get the first flight from Fiftyville one day after the theft
SELECT * FROM flights
WHERE year = 2024 AND
month = 7 AND
day = 29 AND
origin_airport_id = (
  SELECT id FROM airports 
  WHERE full_name LIKE 'Fiftyville%'
)
ORDER BY hour ASC LIMIT 1;
-- flight id = 36, origin_airport_id = 8 and destination_airport_id = 4

-- The list of passengers in the flight
SELECT * FROM passengers 
WHERE flight_id = 36;

-- To know what happened near and after the hour and minute of the crime
SELECT * FROM bakery_security_logs 
WHERE day = 28 AND
month = 7 AND
year = 2024; 

-- To know the license plate of everyone who left after the crime hour and minute
SELECT license_plate, hour, minute FROM bakery_security_logs 
WHERE day = 28 AND
month = 7 AND
year = 2024 AND
activity = 'exit' AND
hour >= 10 AND minute >= 15 AND minute <= 25;

-- To know the people who was in the flight and in the bakery at the date of the crime
SELECT * FROM people
WHERE passport_number IN (
  SELECT passport_number FROM passengers 
  WHERE flight_id = 36) AND
license_plate IN (
  SELECT license_plate FROM bakery_security_logs 
  WHERE day = 28 AND
  month = 7 AND
  year = 2024 AND
  activity = 'exit' AND
  hour >= 10 AND minute >= 15 and minute <= 25);
-- Probably one of these people is the thief

-- Now, discover the phone calls near the theft, made by the suspects
SELECT * FROM phone_calls 
WHERE year = 2024 AND
month = 7 AND
day = 28 AND
caller IN (
  SELECT phone_number FROM people
  WHERE passport_number IN (
    SELECT passport_number FROM passengers 
    WHERE flight_id = 36) AND
  license_plate IN (
    SELECT license_plate FROM bakery_security_logs 
    WHERE day = 28 AND
    month = 7 AND
    year = 2024 AND
    activity = 'exit' AND
    hour >= 10 AND minute >= 15 and minute <= 25)
  AND duration <= 60
);

-- To know the withdraws made in the day of the crime
SELECT * FROM atm_transactions
WHERE year = 2024 AND
month = 7 AND
day = 28 AND
atm_location = 'Leggett Street' AND
transaction_type = 'withdraw';

-- To know the bank_accounts from the withdraws made in the day of the crime
SELECT * FROM bank_accounts 
WHERE account_number IN (
  SELECT account_number FROM atm_transactions
  WHERE year = 2024 AND
  month = 7 AND
  day = 28 AND
  atm_location = 'Leggett Street' AND
  transaction_type = 'withdraw');


-- Know the people in the suspects list who made a withdraw
SELECT * FROM people
WHERE passport_number IN (
  SELECT passport_number FROM passengers 
  WHERE flight_id = 36) AND
license_plate IN (
  SELECT license_plate FROM bakery_security_logs 
  WHERE day = 28 AND
  month = 7 AND
  year = 2024 AND
  activity = 'exit' AND
  hour >= 10 AND minute >= 15 AND minute <= 25) AND
id IN (
  SELECT person_id FROM bank_accounts WHERE account_number IN (
    SELECT account_number FROM atm_transactions
    WHERE year = 2024 AND
    month = 7 AND
    day = 28 AND
    atm_location = 'Leggett Street' AND
    transaction_type = 'withdraw'));
-- The list of suspects shrinked to just Lucca and Bruce

-- Know I need to join every clue, withdraw in the morning, a phone call less than one minute during the rob and the flight
SELECT * FROM people
WHERE passport_number IN (
  SELECT passport_number FROM passengers 
  WHERE flight_id = 36) AND
license_plate IN (
  SELECT license_plate FROM bakery_security_logs 
  WHERE day = 28 AND
  month = 7 AND
  year = 2024 AND
  activity = 'exit' AND
  hour >= 10 AND minute >= 15 AND minute <= 25) AND
id IN (
  SELECT person_id FROM bank_accounts WHERE account_number IN (
    SELECT account_number FROM atm_transactions
    WHERE year = 2024 AND
    month = 7 AND
    day = 28 AND
    atm_location = 'Leggett Street' AND
    transaction_type = 'withdraw')) AND
phone_number IN (
  SELECT caller FROM phone_calls 
  WHERE year = 2024 AND
  month = 7 AND
  day = 28 AND
  caller IN (
    SELECT phone_number FROM people
    WHERE passport_number IN (
      SELECT passport_number FROM passengers 
      WHERE flight_id = 36) AND
    license_plate IN (
      SELECT license_plate FROM bakery_security_logs 
      WHERE day = 28 AND
      month = 7 AND
      year = 2024 AND
      activity = 'exit' AND
      hour >= 10 AND minute >= 15 and minute <= 25)
    AND duration <= 60
)); -- Know, I have discovered that was Bruce

-- To know the person who Bruce called during the rob
SELECT * FROM people 
WHERE phone_number = (
  SELECT receiver FROM phone_calls 
  WHERE caller = '(367) 555-5533' AND
  duration <= 60 AND
  year = 2024 AND
  month = 7 AND
  day = 28
);
