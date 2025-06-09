#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
  int numbers[] = {20, 500, 10, 5, 100, 1, 50};

  int n = get_int("Number: "); // Number to search

  for (int i = 0; i < 7; i++)
  {
    if (numbers[i] == n)
    {
      printf("Found\n");
    } 
    else {
      printf("Not found\n");
    }
  }

  string characters[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};
  string s = get_string("String to search: ");

  for (int i = 0; i < 6; i++) {
    if (strcmp(characters[i], s) == 0) {
      printf("Found\n");
      return 0;
    }
  }
  printf("Not found\n");
  return 1;

}
