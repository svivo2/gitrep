#include "mystrtok.h"

char *mystrtok(char *str, const char *delim)
{
  char * token = NULL;

  i = find_first_in_the_set(str,delim);
  j = find_first_non_in_the_set(i,delim);
  while (*i < *j)
    *token++ = *i++;
  return token;

}
char *find_first_non_in_the_set(char *str, const char *set)
{
  while (*str == *set && str != NULL)
    str++;

  return str;

}
char *find_first_in_the_set(char *str, const char *set)
{
  while (*str != *set && str != NULL)
    str++;

  return str;
}
