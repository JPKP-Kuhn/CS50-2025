#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
  // prints the name of the program
  printf("Program: %s\n", argv[0]);

  // Prints the input when execute the program, ./greet joao
  printf("hello, %s\n", argv[1]);

  if (argc == 3)
  {
    printf("Hello, %s %s\n", argv[1], argv[2]);
  }

  for (int i = 1; i < argc; i++)
  {
    printf("%s\n", argv[i]);
  }
}
