/*
 * Exercise 1-21. Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the same
 * tab stops as for detab. When either a tab or a single blank would suffice to
 * reach a tab stop, which should be given preference?
 */

#include <stdio.h>
#include <stdlib.h>

void entab(int);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("usage: entab n\n");
    return 1;
  }
  int tabstop = atoi(argv[1]);
  if (tabstop < 1)
    tabstop = 1;
  entab(tabstop);
}

void entab(int n) {
  int c, column = 0, blanks = 0;
  while ((c = getchar()) != EOF)
    if (c == ' ')
      ++blanks;
    else {
      if (column + blanks >= n) {
        putchar('\t');
        blanks -= n - column;
        column = 0;
        for (; blanks >= n; blanks -= n)
          putchar('\t');
      }
      for (; blanks > 0; --blanks, ++column)
        putchar(' ');
      putchar(c);
      column = c == '\n' || c == '\t' ? 0 : column == n - 1 ? 0 : column + 1;
    }
}
