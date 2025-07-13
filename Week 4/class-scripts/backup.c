#include "stdio.h"

int main(void)
{
  char *s = "HI!";
  printf("%s\n", s+1);
  for (int i = 0; i < 4; i++)
  {
    printf("%c\n", *(s+i));
  }
}
