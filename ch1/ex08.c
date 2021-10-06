/*
 * Exercise 1-8. Write a program to count blanks, tabs, and newlines.
 */

#include <stdio.h>

int main() {
  int c, counter = 0;
  while ((c = getchar()) != EOF)
    if (c == ' ' || c == '\t' || c == '\v' || c == '\n')
      ++counter;
  printf("%d\n", counter);
}
