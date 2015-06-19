#include<string.h>
#include <stdlib.h>

#include "a.h"

#define HELLO "Hello"

char * a() {
  char * ret = (char*)malloc(strlen(HELLO)+1);

  strcpy(ret, HELLO);

  return ret;
}
