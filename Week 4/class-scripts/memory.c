#include "stdlib.h"

int main(void)
{
  int *x = malloc(3 * sizeof(int));
  x[1] = 32;
  x[2] = 10;
  x[3] = 40;
  // I must include free()
  free(x);
}
