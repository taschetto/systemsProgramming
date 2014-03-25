#include <stdio.h>

float toCelsius(float f);

int main()
{
  float f = 0;
  printf("Fahrenheit: ");
  scanf("%f", &f);
  float c = toCelsius(f);
  printf("%5.2f°F equals to %5.2f°C\n", f, c);
  return 0;
}

float toCelsius(float f)
{
  return 5.0/9.0 * (f - 32);
}
