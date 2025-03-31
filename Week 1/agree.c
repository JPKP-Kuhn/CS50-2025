#include <cs50.h>
#include <stdio.h>

int main(void)
{
  char c = get_char("Você concorda?[s/n] ");
  if (c == 's' || c == 'S')
  {
    printf("Aceitou\n");
  }
  else if (c == 'n' || c == 'N')
  {
    printf("Discordou\n");
  }
}
