#include <ctype.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

string isalphabetic(string text) {
  int s = strlen(text);
  for (int i = 1; i < s; i++) {
    if (text[i] < text[i-1]) {
      return "No";
    }
  }
  return "Yes";
}

int main(void){
  int numbers[5];
  numbers[0] = 1;
  for (int i = 1; i < 5; i++) {
    numbers[i] = 2 * numbers[i-1];
  }

  for (int i = 0; i < 5; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  char word[] = {'H', 'e', 'l', 'l', 'o', '\0'};

  for (int i = 0; i < 5; i++) {
    printf("%c", word[i]);
  }
  printf("\n");
  ///////////////////////////////////////

  string text = get_string("input: \n");
  int s = strlen(text);
  for (int i = 0; i < s; i++) {
    if (isalpha(text[i])) {
      printf("%c  - %d\n", text[i], text[i]);
    }
  }

  // is akphabetic
  string alphabetic = isalphabetic(text);
  printf("%s\n", alphabetic);
  
}

