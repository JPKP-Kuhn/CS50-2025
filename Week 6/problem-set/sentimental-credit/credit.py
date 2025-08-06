number = input("Number: ")
second_last = number[-2::-2]
another_last = number[-1::-2]
total = 0

for n in second_last:
    i = int(n) * 2
    if i > 9:
        total += i // 10 + i % 10
    else:
        total += i

for n in another_last:
    total += int(n)

valid = (total % 10 == 0)

if valid:
    numbers = len(number)
    digit = number[0:2]
    if digit in ['34', '37'] and numbers == 15:
        print("AMEX")
    elif digit in ['51', '52', '53', '54', '55'] and numbers == 16:
        print("MASTERCARD")
    elif number[0] == '4' and (numbers == 13 or numbers == 16):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")

