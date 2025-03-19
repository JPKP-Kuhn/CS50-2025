#include <cs50.h>
#include <stdio.h>

int main(void)
{
  string answer = get_string("Qual é o seu nome? ");
  printf("hello, %s \n", answer);

  return(0);
}
