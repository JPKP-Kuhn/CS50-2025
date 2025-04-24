#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);
void print_space(int spaces);
void print_block(int blocks);
void print_piramid(int spaces, int blocks);

int main(void)
{
  int height = get_positive_int();
  int b = 1;
  int s = height - 1;

  if (s == 0)
  {
    printf("#  #\n");
  }
  else 
  {
     while(s > 0)
    {
      while (b < height) 
      {
        for (int row = 0; row < height; row++)
        {
          print_piramid(s, b);
          b++;
          s--;
        }
      }
    }
  }
}

void print_piramid(int spaces, int blocks)
{
  print_space(spaces);
  print_block(blocks);
  printf("  ");
  print_block(blocks);
  printf("\n");
}

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

// Semelhante ao triangulo pra esquerda, tem os espaços vazios, mas após imprimir ele, preciso dar dois espaçose aí #, linha abaixo, igual, mas 2 #,..
