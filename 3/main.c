#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  long *values;
  int len;
} Primes;

void primes_dump(Primes *primes) {
  for (int i = 0; i < primes->len; i++) {
    printf("  [%d] = %ld\n", i, primes->values[i]);
  }
}

void primes_prepare(Primes *primes, long target) {
  long limit = ceil(sqrt(target));
  long *flags = malloc((target + 1) * sizeof(long));
  for (long i = 2; i <= target; i++) {
    flags[i] = 1;
  }
  for (long i = 2; i <= limit; i++) {
    if (flags[i]) {
      for (long j = 2; i * j <= target; j++) {
        flags[i * j] = 0;
      }
    }
  }
  for (long i = 2; i <= target; i++) {
    if (flags[i]) {
      primes->values[primes->len] = i;
      primes->len++;
    }
  }
  free(flags);
}

void primes_free(Primes *primes) {
  free(primes->values);
  free(primes);
}

Primes *primes_new(long target) {
  Primes *primes = malloc(sizeof(Primes));
  primes->values = malloc(target * sizeof(long));
  primes->len = 0;
  primes_prepare(primes, target);
  primes->values = realloc(primes->values, primes->len * sizeof(long));
  return primes;
}

long solve(long target) {
  Primes *primes = primes_new(target);

  for (int i = primes->len - 1; i >= 0; i--) {
    long p = primes->values[i];
    if (target % p == 0) {
      primes_free(primes);
      return p;
    }
  }

  primes_free(primes);
  return 0;
}

int main(int argc, char **args) {
  long a;

  a = solve(2);
  if (a != 2) {
    printf("expected %ld, but got %ld\n", (long)2, a);
    return 1;
  }

  a = solve(3);
  if (a != 3) {
    printf("expected %ld, but got %ld\n", (long)3, a);
    return 1;
  }

  a = solve(13195);
  if (a != 29) {
    printf("expected %ld, but got %ld\n", (long)29, a);
    return 1;
  }

  a = solve(600851475143);
  printf("answer = %ld\n", a);

  return 0;
}
