// According to github copilot, now this code left-mario.c is well designed
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

void print_row(int spaces, int blocks)
{
  print_space(spaces);
  print_block(blocks);
  printf("\n");
}

int main(void)
{
  int height = get_positive_int();
  
  for (int row = 0; row < height; row++)
  {
    int spaces = height - row;
    print_row(spaces, row);
  }
}
