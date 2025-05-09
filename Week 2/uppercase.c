#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
  string s = get_string("Before: ");

  printf("After: \n");

  for (int i = 0, n = strlen(s); i < n; i++)
  {
    if (s[i] >= 'a' && s[i] <= 'z') // A char is a number in ascii table
    { /*
      // printf("%c", s[i] - ('a' - 'A'));
      printf("%c", toupper(s[i]));
    }
    else 
    {
      printf("%c", s[i]);
    }
    */
      // Can just be:
      printf("%c", toupper(s[i]));
  }
    printf("\n");
}
