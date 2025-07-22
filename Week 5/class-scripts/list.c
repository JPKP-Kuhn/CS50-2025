#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int list[3];

  list[0] = 1;
  list[1] = 2;
  list[2] = 3;

  for (int i = 0; i < 3; i++)
  {
    printf("%i\n", list[i]);
  }

  // New way to create a array
  printf("New way for creating an array:\n");
  int *newList = malloc(3 * sizeof(int));
  if (NULL == newList)
  {
    return 1;
  }
  for (int i = 0; i < 3; i++)
  {
    newList[i] = i+1;
    printf("%i\n", newList[i]);
  }
  // How to realocate a new array a little bigger
  int *temp = realloc(newList, 4 * sizeof(int));
  if (NULL == temp)
  {
    free(newList);
    return 1;
  }

  printf("My temp is:\n");
  /* Is not necessary anymore with realloc
  for (int i = 0; i < 3; i++)
  {
    temp[i] = newList[i];
  }
  */
  temp[3] = 4;

  free(newList);

  newList = temp;
  for (int i = 0; i < 4; i++)
  {
    printf("%i\n", newList[i]);
  }

  // Time passes
  free(newList);
  return 0;
}
