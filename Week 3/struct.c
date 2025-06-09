#include <stdio.h>
#include <cs50.h>
#include <string.h>

// A better solution for search_name_number.c

typedef struct
{
  string name;
  string number;
} person;

int main(void) 
{
  person people[3];

  people[0].name = "João";
  people[0].number = "8323912431";

  people[1].name = "Marai";
  people[1].number = "238023891029";

  people[2].name = "Adri";
  people[2].number = "138491102";

  string name = get_string("Name: ");
  for (int i = 0; i < 3; i++) {
    if (strcmp(people[i].name, name) == 0) {
      printf("Found %s\n", people[i].number);
      return 0;
    }
  }
  printf("Not found\n");
  return 1;
}
