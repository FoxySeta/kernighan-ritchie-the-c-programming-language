/*
 * Exercise 1-5. Modify the temperature conversion program to print the table in
 * reverse order, that is, from 300 degrees to 0.
 */

#include <stdio.h>
/* print Fahrenheit-Celsius table */
int main() {
  const int upper = 300, lower = 0, step = 20;
  for (int fahr = upper; fahr >= lower; fahr -= step)
    printf("%3d %6.1f\n", fahr, 5.0 / 9.0 * (fahr - 32));
}
