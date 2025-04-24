#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

string checksum(long n);
string checkcard(string card, long credit);
int count_digits(long n);

// Luhn's algorithm
int main(void)
{
  
  long credit = get_long("Number: ");
  string card = checksum(credit);

  printf("%s\n", checkcard(card, credit));
}

string checksum(long n)
{
  int sum = 0;
  while (n > 0) 
  {
    int odd_digit = n % 10;
    n /= 10;
    int even_digit = n % 10;
    int two = 2*even_digit;
    if (two > 9)
    {
      sum += (two%10 + two/10);
    } else {
      sum += 2*even_digit + odd_digit;
    }
    n /= 10;
  }
  printf("%i\n", sum);
  if (sum%10 == 0){
    return "VALID";
  } else {
    return "INVALID";
  }
}

string checkcard(string card, long credit)
{  if (strcmp(card, "INVALID") == 0)
  {
    return "INVALID";
  }else {
    int length = count_digits(credit);

    if (length == 15){
      return "AMERICAN EXPRESS";
    } else if (length == 16){
      return "MASTERCARD";
    } else if ((length == 13 || length == 16)){
      return "VISA";
    }
  }
}

int count_digits(long n)
{
    int count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

