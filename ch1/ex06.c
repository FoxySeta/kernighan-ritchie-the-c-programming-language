/*
 * Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
 */

#include <stdio.h>

int main() {
  printf("Enter a character: ");
  printf("Is EOF still absent? %d\n", getchar() != EOF);
}
