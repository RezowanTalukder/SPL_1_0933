#include <stdio.h>
#include "HexDump02.h"


int PrintHex(unsigned char c, int i) {
  if (i == 0 ) {
    printf("%06X  ", i);
  } 
  else {
    if (i%16 == 0)
      printf("\n%06X  ", i);
    else if (i%16 == 8)
      printf(" -- ");
    else
      printf(" ");
  }    

  printf("%02X", c);
  return 0;
}
