/*
 * Exercise 1-14. Write a program to print a histogram of the frequences of
 * different characters in ints input.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define DIM 10

int main() {
  int digitcounters[DIM];
  for (int i = 0; i < DIM; ++i)
    digitcounters[i] = 0;
  char c;
  while ((c = getchar()) != EOF)
    if (isdigit(c))
      ++digitcounters[c - '0'];
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
      if (digitcounters[i] >= row) {
        putchar('*');
        end = false;
      } else
        putchar(' ');
    }
    ++row;
  } while (!end);
  putchar('\n');
}
