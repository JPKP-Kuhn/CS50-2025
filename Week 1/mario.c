#include <stdio.h>

void print_row(int n);

int main(void)
{
  //lazy way
  printf("###\n");
  printf("###\n");
  printf("###\n");

  printf("Smarter way\n");
  //Using for loops
  for (int row = 0; row < 3; row++)
  {
    for (int col = 0; col < 3; col++)
    {
      printf("#");
    }
    printf("\n");
  }
  //Never changes n
  const int n = 3;
  printf("Now using a function\n");
  for (int i = 0; i < n; i++)
  {
    print_row(n);
  }

}
//print n rows
void print_row(int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("#");
  }
  printf("\n");
}
