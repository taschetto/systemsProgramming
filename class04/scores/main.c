/*
 * Em uma competição olímpica, os atletas recebem notas de 0 a 10 de 8 juízes.
 * O menor e o maior valor são descartados, e o valor final da nota é a média
 * dos outros 6. Escreva um programa que leia as 8 notas, coloque-as em um
 * array e calcule a média. Dica: será necessária uma função auxiliar.
 * */

#include <stdio.h>
#define SIZE 8

void readScores(float scores[]);
void printScores(float scores[]);
float avgScore(float scores[]);

int main()
{
  float scores[SIZE] = { 0.0 };

  readScores(scores);
  printScores(scores);

  printf("\n\nAverage Score = %2.2f\n", avgScore(scores));

  return 0;
}

void readScores(float scores[])
{
  int i;
  for (i = 0; i < SIZE; i++)
  {
    printf("Score %d = ", i + 1);
    scanf("%f", &scores[i]);
  }
}

void printScores(float scores[])
{
  int i;
  printf("Scores = ");

  for (i = 0; i < SIZE; i++)
  {
    printf("%2.2f\t", scores[i]);
  }
}

float avgScore(float scores[])
{
  int i = 0;
  float sum = 0, max = 0, min = 10;
  for (i = 0; i < SIZE; i++)
  {
    sum += scores[i];

    if (scores[i] > max)
      max = scores[i];

    if (scores[i] < min)
      min = scores[i];
  }

  sum = sum - max - min;

  return sum / (SIZE - 2);
}
