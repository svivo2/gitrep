#include "mystrcat.h"

char * mystrcat(char * result, const char * string)
{

  while (*result != '\0')
    *result++;

  while (*string != '\0')
    *result++ = *string++;
    
  *result = '\0';

  return result;
}
