#include <cs50.h>
#include <stdio.h>

int get_positive_int(void)
{
  int n;
  do 
  {
    n = get_int("Height: ");
  }
  while (n < 1);
  return n;
}

void print_space(int spaces)
{
  for (int s = 0; s < spaces; s++)
  {
    printf(" ");
  }
}

void print_block(int blocks)
{
  for (int b = 0; b < blocks; b++)
  {
    printf("#");
  }
}

int main(void)
{
  int height = get_positive_int();
  int i = 1;
  int s = height - 1;
  if (s == 0)
  {
    printf("#\n");
  }
  else 
  {
  
    while(s > 0)
    {
      while (i < height) 
      {
        for (int row = 0; row < height; row++)
        {
          print_space(s);
          print_block(i);
          printf("\n");
          i++;
          s--;
        }
      }
    }
  }
}

// printa height - 1 espaços, depois #, depois printa height - 2 e depois ##, ..
