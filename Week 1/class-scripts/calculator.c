#include <cs50.h>
#include <stdio.h>

int soma(int x, int y);

void main(void)
{
  int x = get_int("x: ");
  int y = get_int("y: ");

  int sum = soma(x, y);
  printf("The result is: %i \n", sum);

  printf("Now it's multiplication\n");
  printf("%i\n", x*2);

  long dollars = 1;
  while (true)
  {
    char c = get_char("Here is a $%li dollar. Double it and give to the next person?[y/n] ", dollars);
    if (c == 'y')
    {
      dollars *= 2;
    }
    else 
    {
      break;
    }
  }
  printf("Here is the total: %li\n", dollars);

  printf("Now it's the division\n");

  int a = get_int("a: ");
  int b = get_int("b: ");

  printf("%.3f\n", (float) a / b);
}

int soma(int x, int y)
{
  return x + y;
}
