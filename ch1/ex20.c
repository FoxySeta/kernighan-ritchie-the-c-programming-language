/*
 * Exercise 1-20. Write a program detab that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop. Assume a fixed set of
 * tab stops, say every n columns. Should n be a variable or a symbolic
 * parameter?
 */

#include <stdio.h>
#include <stdlib.h>

void detab(int);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("usage: detab n\n");
    return 1;
  }
  int tabstop = atoi(argv[1]);
  if (tabstop < 1)
    tabstop = 1;
  detab(tabstop);
}

void detab(int n) {
  int c, column = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      for (; column < n; ++column)
        putchar(' ');
      column = 0;
    } else {
      putchar(c);
      column = c == '\n' ? 0 : column == n - 1 ? 0 : column + 1;
    }
  }
}
