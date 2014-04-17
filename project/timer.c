#include <arch/nxp/lpc23xx.h>
#include "defines.h"
#include "timer.h"

void wait(int t)
{
  unsigned int tf;
  tf = T0TC + t;
  while (tf != T0TC);
}

void TIMERinit()
{
  T0TCR = 0;			
  T0PR = CCLK / 1000 - 1;	
  T0TCR = 2;			
  T0TCR = 1;			
}
