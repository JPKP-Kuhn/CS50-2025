#include <stdio.h>
#include <cs50.h>

void draw(int n);
void newDraw(int n);

int main(void)
{
  int height = get_int("Height: ");
  draw(height);

  printf("Now let's do it with a recursive function!\n");
  newDraw(height);
}

void draw(int n)
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i+1; j++) {
      printf("#");
    }
    printf("\n");
  }
}

void newDraw(int n)
{
  if (n <= 0)
  {
    return;
  }

  newDraw(n-1);

  for (int i = 0; i < n; i++) 
  {
    printf("#");
  }
  printf("\n");
}
