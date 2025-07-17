#include "helpers.h"
#include <math.h>

int min(int a, int b)
{
  return (a < b) ? a : b;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      int blue = image[i][j].rgbtBlue;
      int green = image[i][j].rgbtGreen;
      int red = image[i][j].rgbtRed;

      int sum = blue + green + red;
      int average = round(sum/3.0);

      image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = average;
    }
  }
  return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      int blue = image[i][j].rgbtBlue;
      int green = image[i][j].rgbtGreen;
      int red = image[i][j].rgbtRed;

      int sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);
      int sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
      int sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);

      image[i][j].rgbtRed = min(sepiaRed, 255);
      image[i][j].rgbtBlue = min(sepiaBlue, 255);
      image[i][j].rgbtGreen = min(sepiaGreen, 255);
    }
  }
  return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width/2.0; j++)
    {
      RGBTRIPLE temp = image[i][j];
      image[i][j] = image[i][width-1-j];
      image[i][width-1-j] = temp;
    }
  }
  return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
  RGBTRIPLE copy[height][width];
  int row[8] = {0, 1, 1, 1, 0, -1, -1, -1};
  int col[8] = {1, 1, 0, -1, -1, -1, 0, 1};
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      int sumRed = image[i][j].rgbtRed;
      int sumBlue = image[i][j].rgbtBlue;
      int sumGreen = image[i][j].rgbtGreen;
      int numbers = 1;
      for (int n = 0; n < 8; n++)
      {
        int nrow = i + row[n];
        int ncol = j + col[n];
        if ((0 <= nrow && height > nrow) && (0 <= ncol && width > ncol))
        {
          sumRed += image[nrow][ncol].rgbtRed;
          sumBlue += image[nrow][ncol].rgbtBlue;
          sumGreen += image[nrow][ncol].rgbtGreen;
          numbers++;
        }
      }
      copy[i][j].rgbtRed = round((double)sumRed/numbers);
      copy[i][j].rgbtBlue = round((double)sumBlue/numbers);
      copy[i][j].rgbtGreen = round((double)sumGreen/numbers);
    }
  }

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      image[i][j] = copy[i][j];
    }
  }
  return;
}
