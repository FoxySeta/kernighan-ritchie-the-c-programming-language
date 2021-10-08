/*
 * Exercise 1-19. Write a function reverse(s) that reverses the character
 * string s. Use it to write a program that reverses its input a line at a time.
 */

#include <stdint.h>
#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

char line[MAXLINE]; /* current input line */

int mygetline(void);
void reverse(int);

/* print longest input line; specialized version */
int main() {
  int len;
  while ((len = mygetline()) > 0) {
    reverse(len);
    printf("%s\n", line);
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

void reverse(int len) {
  for (int i = 0; i < len / 2; ++i) {
    char temp = line[i];
    line[i] = line[len - 1 - i];
    line[len - 1 - i] = temp;
  }
}
