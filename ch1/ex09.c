/*
 * Exercise 1-9. Write a program to copy its input to its output, replacing each
 * string of one or more blanks by a single blank.
 */

#include <stdbool.h>
#include <stdio.h>

int main() {
  bool blankSequence = false;
  int current;
  while ((current = getchar()) != EOF) {
    if (!blankSequence || current != ' ')
      putchar(current);
    blankSequence = current == ' ';
  }
}
