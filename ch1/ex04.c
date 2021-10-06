/*
 * Exercise 1-4. Write a program to print the corresponding Celsius to
 * Fahrenheit table.
 */

#include <stdio.h>

/* print Celsius-Fahrenheit table
for celsius = 0, 20, ..., 300; floating-point version */
int main() {
  const int lower = 0, /* lower limit of temperatuire scale */
      upper = 300,     /* upper limit */
      step = 20;       /* step size */

  printf(" °C     °F\n");
  for (int celsius = lower; celsius <= upper; celsius += step)
    printf("%3d %6.1f\n", celsius, 9.0 / 5.0 * celsius + 32.0);
}
