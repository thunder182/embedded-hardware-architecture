
#include <stdint.h>
#include <stdlib.h>
#include "misc.h"

static int g1;
const int g2 = 45;
char g3 = 12;
char g4 = 0;
extern char g5[N];

int main()
{
  register int l1;
  int * l2;
  volatile int l3 = 12;

  l2 = (int *) malloc( N * g2 * sizeof(char) );

  if ( ! l2 )
  {
    return -1;
  }

  for( l1 = 0; l1 < g2; l3++)
  {
    g1 = func(l2);
  }

  return 0;
}
