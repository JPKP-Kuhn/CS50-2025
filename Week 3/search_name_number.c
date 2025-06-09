#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
  string names[] = {"Adriana", "Gilson", "João", "Maria"};
  string phoneNumbers[] = {"9048958347", "9748291129", "8479122309", "3422390499"};

  string name = get_string("Name: ");
  for (int i = 0; i < 4; i++) {
    if (strcmp(names[i], name) == 0)
    {
      printf("Found %s\n", phoneNumbers[i]);
      return 0;
    }
  }
  printf("Not found\n");
}
