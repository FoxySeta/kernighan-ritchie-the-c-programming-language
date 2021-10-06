/*
 * Exercise 1-12. Write a program that prints its input one word per line.
 */

#include <stdbool.h>
#include <stdio.h>

int main() {
  int c, insideWord = false;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (insideWord)
        putchar('\n');
      insideWord = false;
    } else {
      putchar(c);
      insideWord = true;
    }
  }
}
