#include "mystrlen.h"

size_t mystrlen(const char * string)
{
  size_t len = 0;
  while (string[len] != '\0')
    len++;

  return len;

}
