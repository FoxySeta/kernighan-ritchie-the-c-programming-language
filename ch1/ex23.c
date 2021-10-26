/*
 * Exercise 1-23. Write a program to remove all comments from a C program. Don't
 * forget to handle quoted strings and character constants properly. C comments
 * don't nest.
*/

#include <stdbool.h>
#include <stdio.h>

// not handling escape sequences
int main() {
  int c;
  char prev = getchar();
  bool singlelinecomment = false, multilinecomment = false;
  while ((c = getchar()) != EOF) {
    if (singlelinecomment) {
      if (c == '\n') {
        singlelinecomment = false;
        putchar('\n');
        c = getchar();
      }
    } else if (multilinecomment) {
      if (prev == '*' && c == '/') {
        multilinecomment = false;
        c = getchar();
      }
    } else {
      if (prev == '/' && c == '/')
        singlelinecomment = true;
      else if (prev == '/' && c == '*')
        multilinecomment = true;
      else if (prev == '"') {
        while (c != '"') {
          putchar(prev);
          prev = c;
          c = getchar();
          if (c == EOF) {
            putchar(prev);
            return 0;
          }
        };
        putchar(prev);
        putchar('"');
        c = getchar();
      } else
        putchar(prev);
    }
    prev = c;
  }
}
