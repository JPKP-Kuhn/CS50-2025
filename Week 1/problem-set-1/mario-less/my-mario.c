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

void print_block(int blocks){
  for (int b = 0; b < blocks; b++)
  {
    printf("#");
  }
}

int main(void)
{
  int height = get_positive_int();
  int i = 1;
  while (i < height)
  {
    for (int row = 0; row < height; row++)
    {
      print_block(i);
      printf("\n");
      i++;
    }
  }
}
// print #, pula linha printa ##, pula linha printa ### e assim até printar a quantidade de height

