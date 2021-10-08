/*
 * Exercise 1-17. Write a program to print all input lines that are longer than
 * 80 characters.
 */

#include <stdint.h>
#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

char line[MAXLINE]; /* current input line */

int mygetline(void);

/* print longest input line; specialized version */
int main() {
  int len;
  const int threshold = 80;
  while ((len = mygetline()) > 0)
    if (len > threshold)
      printf("%s\n", line);
  return 0;
}

/* getline: specialized version */
int mygetline(void) {
  char c;
  int i;
  extern char line[];
  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}
