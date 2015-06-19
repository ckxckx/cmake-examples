#include <stdio.h>
#include <stdlib.h>

#include "c.h"

int main(int argc, char ** argv) {
  char * str = c();
  printf("%s\n", str);
  free(str);
  return 0;
}
