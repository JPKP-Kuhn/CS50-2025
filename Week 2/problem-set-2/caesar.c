#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

bool is_numeric(string s);

int main(int argc, string argv[])
{
  if (argc != 2)
  {
    printf("Usage ./caesar key\n");
    return 1;
  }
  if (!is_numeric(argv[1]))
  {
    printf("Usage ./caesar key\n");
    return 1;
  }
  int key = atoi(argv[1]);

  string plaintext = get_string("plaintext: ");
  int lenplain = strlen(plaintext);
  char ciphertext[lenplain+1];

  for (int i = 0; i < lenplain; i++)
  {
    if (isupper(plaintext[i]))
    {
      ciphertext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A';
    }
    else if (islower(plaintext[i]))
    {
      ciphertext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';
    }
    else 
    {
      ciphertext[i] = plaintext[i];   
    }
  }
  ciphertext[lenplain] = '\0';
  printf("ciphertext: %s\n", ciphertext);

  return 0;

}


bool is_numeric(string s)
{
  if (s == NULL || strlen(s) == 0) return false;

  for (int i = 0, n = strlen(s); i < n; i++)
  {
    if (!isdigit(s[i])) return false;
  }
  return true;
}


