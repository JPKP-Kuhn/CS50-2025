#include <stdio.h>
#include <cs50.h>

int main(void)
{
  char c1 = 'H';
  char c2 = 'I';
  char c3 = '!';

  printf("%c%c%c\n", c1,c2,c3);
  printf("%i %i %i\n", c1,c2,c3);

  string s = "OI!";
  printf("%s\n", s);
  printf("Com índice de array: %c%c%c\n", s[0], s[1], s[2]);
  printf("%i %i %i %i É o fim. Mas posso continuar, %i\n", s[0], s[1], s[2], s[3], s[4]);

  string t = "BYE!"; // Fica armazenado logo após o fim da string s

  string words[2];
  words[0] = "HI!";
  words[1] = "BYE!";

  printf("%c%c%c\n", words[0][0], words[0][1], words[0][2]); // Primeiro pro índice 0, depois pro caracter, um array de array de caracteres
  printf("%c%c%c\n", words[1][0], words[1][1], words[1][2]); // Primeiro pro índice 0, depois pro caracter, um array de array de caracteres
}
