#include <stdio.h>
#include <cs50.h>
#include <stdint.h>

int main(int argc, string argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./pdf input.pdf\n");
    return 1;
  }
  // open the file
  FILE *input = fopen(argv[1], "r");

  // create a buffer for file
  uint8_t buffer[4];

  // Create an array of signature bytes, it will identify if is a PDF by it beggining
  uint8_t signature[] = {0x25, 0x50, 0x44, 0x46};

  // Read first 4 bytes from file
  fread(buffer, sizeof(uint8_t), 4, input);

  // cehck the first 4 bytes again signature
  for (int i = 0; i < 4; i++)
  {
    if (signature[i] != buffer[i])
    {
      printf("It is not a PDF file\n");
      fclose(input);
      return 0;
    }
  }

  printf("It is a PDF file\n");

  fclose(input);
}

