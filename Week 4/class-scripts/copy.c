#include "ctype.h"
#include "stdio.h"
#include "cs50.h"
#include <stdlib.h>
#include "string.h"

int main(void)
{
  char *s = get_string("s: ");

  char *t = malloc(strlen(s) + 1); // Me dê 4 bytes ou o tamanho de s + o \0 e armazene o endereço do primeiro byte em t;
  if (t == NULL){
    return 1;
  }

  // for (int i = 0, n = strlen(s); i <= n; i++){
  //   t[i] = s[i];
  // }
  // Solução melhor para fazer uma cópia
  strcpy(t, s);
  if (strlen(t) > 0){
    t[0] = toupper(t[0]);
  }

  printf("s: %s\n", s);
  printf("t: %s\n", t);


  free(t);
}
