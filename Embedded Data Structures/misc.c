
#include "misc.h"

#define SOME_VALUE (6)

int g5[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int func(int * f1)
{
  static int f2;
  unsigned int f3 = 0;
  volatile char * f4 = "Hello World!\n";

  f2++;
  *(&g5[0] + f2) = f3;

  for (f3 = 0; f3 < SOME_VALUE; f3++)
  {
    g5[f3] = f4[f3];
    f2++;
  }

  return f2;
}
