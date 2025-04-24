#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);
// without pointers
int main(void)
{
  int change = get_positive_int();
  int coins = 0;
  if (change >= 25)
  {
    do{
      change -= 25;
      coins++;
    } while(change >= 25);
  } 
  if (change >= 10)
  {
    do {
      change -= 10;
      coins++;
    } while (change >= 10);
  }
  if (change >= 5)
  {
    do {
      change -= 5;
      coins++;
    } while (change >= 5);
  }
  if (change >= 1)
  {
    do {
      change -= 1;
      coins++;
    } while (change >= 1);
  }

  printf("Coins: %i\n", coins);
  printf("Change: %i\n", change);
}

int get_positive_int(void)
{
  int n;
  do {
    n = get_int("Change owed: ");
  } while (n < 0);
  return n;
}
