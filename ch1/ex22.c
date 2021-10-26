/*
 * Exercise 1-22. Write a program to ``fold'' long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before the specified column.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void fold(int);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("usage: fold n\n");
    return 1;
  }
  int tabstop = atoi(argv[1]);
  if (tabstop < 1)
    tabstop = 1;
  fold(tabstop);
}

void fold(int n) {
  int c, column = 0;
  char prev = '\0';
  while ((c = getchar()) != EOF) {
      if (column + 1 == n) {
        if (isgraph(prev) && isgraph(c))
          putchar('-');
        putchar('\n');
        column = 0;
      }
      putchar(c);
      column = c == '\n' ? 0 : column + 1;
      prev = c;
  }
}
