#include<string.h>
#include <stdlib.h>

#include "b.h"

#define WORLD ", world"

char * b() {
  char * a_str = a();
  char * ret = (char*)malloc(strlen(a_str)+strlen(WORLD)+1);

  strcpy(ret, a_str);
  strcat(ret, WORLD);

  return ret;
}
