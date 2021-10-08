/*
 * Exercise 1-18. Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines.
 */

#include <stdint.h>
#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

char line[MAXLINE]; /* current input line */

int mygetline(void);
void trimend(int);

/* print longest input line; specialized version */
int main() {
  int len;
  while ((len = mygetline()) > 0) {
    trimend(len);
    printf("[%s]\n", line);
  }
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

void trimend(int len) {
  int back = len - 1;
  while (back > -1 &&
         (line[back] == ' ' || line[back] == '\t' || line[back] == '\n'))
    --back;
  line[back + 1] = '\0';
}
