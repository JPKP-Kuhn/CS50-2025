#include <stdio.h>
#include <cs50.h>

const int N = 3;

float average(int length, int array[]);

int main(void)
{
  int scores[N];
  for (int i = 0; i < N; i++)
  {
    scores[i] = get_int("Score: ");
  }

  // Vai causar stack smashing detected, ou buffer overflow. Está tentando inserir um valor a mais na lista que não tem espaço
  // scores[3] = 1;
  printf("Average: %f\n", average(N, scores));
}

float average(int length, int array[]) // É importante passar o tamanho do array
{
  int sum = 0;
  for (int i = 0; i < length; i++)
  {
    sum += array[i];
  }
  return sum / (float) length;
}
