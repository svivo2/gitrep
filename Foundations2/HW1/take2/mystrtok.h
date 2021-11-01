#ifndef MYSTRTOK_H
#define	MYSTRTOK_H

#include <cstdlib>

char *mystrtok(char *str, const char *delim);
char *find_first_non_in_the_set(char *str, const char *set);
char *find_first_in_the_set(char *str, const char *set);
static char * i, *j;
#define strtok mystrtok
#endif	/* MYSTRLEN_H */
