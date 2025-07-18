#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// The camera writes in units of 512B
#define BLOCK 512
#define FILENAME_LENGTH 8

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./recover card.raw\n");
    return 1;
  }

  FILE *card = fopen(argv[1], "r");
  if (NULL == card)
  {
    printf("Could not open the file %s", argv[1]);
    return 1;
  }

  uint8_t buffer[BLOCK];

  // Now, I need to find where a JPEG start. The start demarks the and of the previous
  // The 3 first bytes are 0xff 0xd8 0xff
  // and the fourth will start with 1110
  int jpg_files = 0;
  FILE *jpg = NULL;
  char filename[8];
  // while there is still data left to read
  while(fread(buffer, 1, BLOCK, card) == 512){
    // Create JPEG from the data;
    if (buffer[0] == 0xff && 
      buffer[1] == 0xd8 && 
      buffer[2] == 0xff && 
      (buffer[3] & 0xf0) == 0xe0)
    {
      // found a jpg file
      // Name of each file is ###.jpg

      if (jpg != NULL)
      {
        fclose(jpg);
      }

      sprintf(filename, "%03i.jpg", jpg_files++);
      jpg = fopen(filename, "w");
      if (NULL == jpg){
        printf("Could not open the file %s", filename);
        return 1;
      }
      fwrite(buffer, 1, BLOCK, jpg);
    } 
    else {
      if (jpg_files > 0){
        fwrite(buffer, 1, BLOCK, jpg);
      }
    }
  }

  fclose(jpg);
  fclose(card);
}
