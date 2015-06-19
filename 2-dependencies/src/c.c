#include<string.h>
#include <stdlib.h>

#include "c.h"

char * c() {
  char * b_str = b();
  char * ret = (char*)malloc(strlen(b_str)+2);

  strcpy(ret, b_str);
  strcat(ret, "!");

  return ret;
}
