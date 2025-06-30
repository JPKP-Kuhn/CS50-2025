#include <stdio.h>
#include <cs50.h>

int f(int number);

int main(void)
{
  int number;
  do {
    number = get_int("Number: ");
  }while (number < 0);

  int result = f(number);
  printf("Factorial of %i is %i.\n", number, result);
}

int f(int n){
  // Base case, when it will stop?
  if (n == 0)
  {
    return 1;
  }
  else {
    // Recursive case
    return n * f(n-1);
  }
}
