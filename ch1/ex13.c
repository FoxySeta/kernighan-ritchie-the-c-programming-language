/*
 * Exercise 1-13. Write a program to print a histogram of the lengths of words
 * in its input. It is easy to draw the histogram with the bars horizontal; a
 * vertical orientation is more challenging.
 */

#include <stdbool.h>
#include <stdio.h>

#define DIM 10

int main() {
  int lengthcounters[DIM], currentlength = 0;
  for (int i = 0; i < DIM; ++i)
    lengthcounters[i] = 0;
  char c;
  while ((c = getchar()) != EOF)
    if (c == ' ' || c == '\n' || c == '\t') {
      if (currentlength)
        ++lengthcounters[currentlength];
      currentlength = 0;
    } else if (currentlength + 1 < DIM)
      ++currentlength;
  if (currentlength)
    ++lengthcounters[currentlength];
  putchar('\n');
  for (int i = 0; i < DIM; ++i)
    printf(" %d", i);
  putchar('\n');
  for (int i = 0; i < DIM; ++i)
    printf("  ");
  bool end;
  int row = 1;
  do {
    putchar('\n');
    end = true;
    for (int i = 0; i < DIM; ++i) {
      putchar(' ');
      if (lengthcounters[i] >= row) {
        putchar('*');
        end = false;
      } else
        putchar(' ');
    }
    ++row;
  } while (!end);
  putchar('\n');
}
