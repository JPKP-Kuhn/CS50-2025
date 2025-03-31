#include <stdio.h>
#include <cs50.h>

int main(void)
{
  int x = get_int("Valor para x: \n");
  int y = get_int("Valor para y: \n");

  if (x < y)
  {
    printf("x é menor do que y\n");
  }
  else if (x > y)
  {
    printf("x não é menor do que y\n");
  }
  else
  {
    printf("x é igual a y\n");
  }
}
