#include <stdio.h>
#include <cs50.h>
#include <string.h>

int string_length(string word);

int main(void)
{
  string name = get_string("Name: ");

  int length = string_length(name);
  printf("%i\n", length);

  // Or simply
  int lng = strlen(name);
  printf("%i\n", lng);
}

int string_length(string word)
{
  int n = 0;
  while (word[n] != '\0')
  {
    n++;
  }
  // print the length of the string
  return n;
}
