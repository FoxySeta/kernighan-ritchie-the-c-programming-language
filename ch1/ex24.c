/*
 * Exercise 1-24. Write a program to check a C program for rudimentary syntax
 * errors like unmatched parentheses, brackets and braces. Don't forget about
 * quotes, both single and double, escape sequences, and comments. (This program
 * is hard if you do it in full generality.)
 */

#include <stdio.h>
#include <stdlib.h>

void expecting(int);

int main() {
  expecting(EOF);
}

void expecting(int expectation) {
  int c;
  while ((c = getchar()) != expectation) {
    if (expectation != '"' && expectation != '\'' && expectation != '\n'
      && expectation != '*')
      switch (c) {
      case '(':
        expecting(')');
        break;
      case '[':
        expecting(']');
        break;
      case '{':
        expecting('}');
        break;
      case ')':
      case ']':
      case '}':
        printf("\nError: unmatched %c.\n", c);
        exit(1);
      case '\'':
      case '"':
        expecting(c);
        break;
      case '\\':
        getchar();
        break;
      case '/':
        c = getchar();
        if (c == '/')
          expecting('\n');
        else if (c == '*')
          expecting('*');
        break;
      case EOF:
        printf("\nError: end of file before matching %c.\n", expectation);
        exit(1);
      }
    else if (c == EOF) {
      printf("\nError: end of file before matching */.\n");
      exit(1);
    }
  }
  if (expectation == '*' && getchar() != '/')
    expecting('*');
}
