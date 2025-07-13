#include <stdio.h>

typedef char* string;
int main(void)
{
  int n = 50;
  int *p = &n;
  printf("Value of n: %i\n", *p);
  printf("Address of n: %p\n", p);

  string s = "HI!";
  printf("%s\n", s);
  printf("%p\n", s);
  printf("%p\n", &s[0]);
  printf("%p\n", &s[1]);
  printf("%p\n", &s[2]);
  printf("%p\n", &s[3]);
  printf("%c\n", s[4]); // out of the string

  char *word = "string";
  printf("%s\n", word);
}
