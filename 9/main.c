#include <stdio.h>
#include <math.h>

/*
 * a^2 + b^2 = c^2, a + b + c = 1000, 1 <= a < b < c
 * a >= 1, b >= 2, c >= 3
 * 1000 = c + b + a >= c + 2 + 1 = c + 3 <-> c <= 997
 *
 */
int main(int argc, char **args) {
  int a, b, c;
  for (c = 1; c <= 1000; c++) {
    for (a = 1; a < c; a++) {
      b = 1000 - a - c;
      if (a >= b) continue;
      if (b >= c) continue;
      if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
        printf("abc = %d\n", a * b* c);
        return 0;
      }
    }
  }
  printf("not found\n");
  return 1;
}
