#include <stdio.h>
#include <cs50.h>

void print_column(int h);

int main(void)
{ // Queria fazer printf(#) 3 vezes, desse jeito serão 4
  for (int i = 0; i <= 3; i++)
  {
    //printf("i é %i \n, i");
    printf("#\n");
  }
    int h = get_int("Altura: ");
    print_column(h);
}

void print_column(int h)
{
  for (int i = 0; i < h; i++)
  {
    printf("#\n");
  }
}
