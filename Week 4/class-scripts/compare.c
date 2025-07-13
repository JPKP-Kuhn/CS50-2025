#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
  char *s = get_string("s: ");
  char *t = get_string("t: ");
  char **p = &s;
  printf("%p\n", p);

  printf("Pointer s and t\n");
  printf("%p\n", s);
  printf("%p\n", t);

  if (strcmp(s, t) == 0)
  {
    printf("Same\n");
  }
  else 
  {
    printf("Different\n");
  }

}
