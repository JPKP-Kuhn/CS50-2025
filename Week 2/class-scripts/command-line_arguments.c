#include <ctype.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (int argc, string argv[]) {
  if (argc != 2) {
    printf("You must provide a word as argument!\n");
    return 1;
  }
  string text = argv[1];
  int size = strlen(text);

  for (int i = 0; i < size; i++) {
    if (!isalpha(text[i])) {
      printf("Your word must contain only letter!\n");
      return 2;
    }
  }

  for (int i = 1; i < size; i++) {
    if (text[i] < text[i-1]) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}
