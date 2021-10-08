/*
 * Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to
 * use a function for conversion.
 */

#include <stdio.h>

float celsius(int fahr);

/* print Fahrenheit-Celsius table */
int main() {
  const int lower = 0, upper = 300, step = 20;
  for (int fahr = lower; fahr <= upper; fahr += step)
    printf("%3d %6.1f\n", fahr, celsius(fahr));
}

float celsius(int fahr) { return 5.0 / 9.0 * (fahr - 32); }
