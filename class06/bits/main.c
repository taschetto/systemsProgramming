#include <stdio.h>

typedef unsigned int uint;

uint clear(uint val);
uint setbit(uint val, int bit);
uint clearbit(uint val, int bit);
uint invertbit(uint val, int bit);
uint testbit(uint val, int bit);

void printbits(uint val);

int main()
{
  uint val = 0x00;
  printf("val = %u\n", val);
  val = setbit(val, 7);
  printf("setbit(val, 7) = %u\n", val);
  printf("testbit(val, 7) = %u\n", testbit(val, 7));
  val = setbit(val, 3);
  printf("setbit(val, 3) = %u\n", val);
  val = clearbit(val, 3);
  printf("clearbit(val, 3) = %u\n", val);
  val = invertbit(val, 3);
  printf("invertbit(val, 3) = %u\n", val);
  printf("testbit(val, 3) = %u\n", testbit(val, 3));
  
  return 0;
}

uint clear(uint val)
{
  uint mask = 0x00;
  return val & mask;
}


uint setbit(uint val, int bit)
{
  uint mask = 1 << bit;
  return val | mask;
}


uint clearbit(uint val, int bit)
{
  uint mask = 1 << bit;
  return val & ~mask;
}

uint invertbit(uint val, int bit)
{
  uint mask = 1 << bit;
  return val ^ mask;
}

uint testbit(uint val, int bit)
{
  uint mask = 1 << bit;
  return (val & mask) >> bit;
  // return val & mask > 0;
}
