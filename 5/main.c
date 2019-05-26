#include <stdio.h>

long gcd(long m, long n) {
  // assure m >= n
  if (m < n) {
    long tmp = m;
    m = n;
    n = tmp;
  }

  while (n > 0) {
    long tmp = n;
    n = m % tmp;
    m = tmp;
  }

  return m;
}

long lcm(long m, long n) {
  return m * n / gcd(m, n);
}

long solve(long target) {
  long a = 1;
  for (long i = 1; i <= target; i++) {
    a = lcm(a, i);
  }
  return a;
}

int main(int argc, char **args) {
  long a;

  a = solve(5);
  if (a != 60) {
    printf("expected %ld but got %ld\n", (long)60, a);
    return 1;
  }

  a = solve(10);
  if (a != 2520) {
    printf("expected %ld but got %ld\n", (long)2520, a);
    return 1;
  }

  a = solve(20);
  printf("answer = %ld\n", a);
  return 0;
}
