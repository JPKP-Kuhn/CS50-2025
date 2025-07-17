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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
  // Sobel operator

  int gx[8] = {-1, 0, 1, -2, 2, -1, 0, 1};
  int gy[8] = {-1,-2,-1,  0, 0,  1, 2, 1};

  RGBTRIPLE copy[height][width];

  int row[8] = {-1, -1, -1,  0,  0, 1, 1, 1};
  int col[8] = {-1,  0,  1, -1,  1,-1, 0, 1};

  // all the corners will be black. simplefy the math
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      copy[i][j] = image[i][j];
    }
  }

  // edge detection
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      int sumRedx = 0, sumRedy = 0;
      int sumBluex = 0, sumBluey = 0;
      int sumGreenx = 0, sumGreeny = 0;

      for (int n = 0; n < 8; n++)
      {
        int nrow = i + row[n];
        int ncol = j + col[n];

        if (nrow < 0 || nrow >= height || ncol < 0 || ncol >= width)
        {
          continue;
        }

        int red = copy[nrow][ncol].rgbtRed;
        int blue = copy[nrow][ncol].rgbtBlue;
        int green = copy[nrow][ncol].rgbtGreen;

        sumRedx += gx[n] * red;
        sumRedy += gy[n] * red;

        sumBluex += gx[n] * blue;
        sumBluey += gy[n] * blue;

        sumGreenx += gx[n] * green;
        sumGreeny += gy[n] * green;
      }
      // Calculating the sobel values
      int sobelR = round(sqrt(sumRedx * sumRedx + sumRedy * sumRedy));
      int sobelB = round(sqrt(sumBluex * sumBluex + sumBluey * sumBluey));
      int sobelG = round(sqrt(sumGreenx * sumGreenx + sumGreeny * sumGreeny));

      image[i][j].rgbtRed = min(sobelR, 255);
      image[i][j].rgbtBlue = min(sobelB, 255);
      image[i][j].rgbtGreen = min(sobelG, 255);
    }
  }
  return;
}
