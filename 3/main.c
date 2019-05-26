#include <stdio.h>
#include <stdlib.h>

typedef struct {
  long *data;
  int capacity;
  int len;
} Vector;

Vector *vec_new(void) {
  Vector *v = malloc(sizeof(Vector));
  v->len = 0;
  v->capacity = 16;
  v->data = malloc(sizeof(long) * v->capacity);
  return v;
}

void vec_free(Vector *v) {
  free(v->data);
  free(v);
}

void vec_push(Vector *v, long elm) {
  if (v->len >= v->capacity) {
    v->capacity *= 2;
    v->data = realloc(v->data, sizeof(long) * v->capacity);
  }
  v->data[v->len++] = elm;
}

long vec_length(Vector *v) {
  return v->len;
}

long vec_last(Vector *v) {
  return v->data[v->len - 1];
}

long vec_get(Vector *v, int i) {
  return v->data[i];
}

typedef struct {
  Vector *primes;
} PG;

PG *pg_new(void) {
  PG *pg = malloc(sizeof(PG));
  pg->primes = vec_new();
  return pg;
}

void pg_free(PG *pg) {
  vec_free(pg->primes);
  free(pg);
}

int pg_is_prime(PG *pg, long try) {
  for (int i = 0; i < vec_length(pg->primes); i++) {
    long p = vec_get(pg->primes, i);
    if (try % p == 0) {
      return 0;
    }
  }

  return 1;
}

long pg_next(PG *pg) {
  if (vec_length(pg->primes) == 0) {
    vec_push(pg->primes, (long)2);
  } else if (vec_length(pg->primes) == 1) {
    vec_push(pg->primes, (long)3);
  } else {
    long try = vec_last(pg->primes);
    while (1) {
      try += (long)2;
      if (pg_is_prime(pg, try)) {
        vec_push(pg->primes, try);
        break;
      }
    }
  }
  return vec_last(pg->primes);
}

long resolve(long target) {
  Vector *factors = vec_new();

  long p;
  PG *pg = pg_new();
  while ((p = pg_next(pg)) <= target) {
    if (target % p == 0) {
      vec_push(factors, p);
    }
  }
  pg_free(pg);

  long result = vec_last(factors);
  vec_free(factors);
  return result;
}

int main(int argc, char **args) {
  long a;

  a = resolve(3);
  if (a != 3) {
    printf("expected %ld but got %ld\n", (long)3, a);
    return 1;
  }

  a = resolve(4);
  if (a != 2) {
    printf("expected %ld but got %ld\n", (long)2, a);
    return 1;
  }

  a = resolve(6);
  if (a != 3) {
    printf("expected %ld but got %ld\n", (long)3, a);
    return 1;
  }

  a = resolve(13195);
  if (a != 29) {
    printf("expected %ld but got %ld\n", (long)29, a);
    return 1;
  }

  a = resolve(600851475143);
  printf("answer = %ld\n", a);

  return 0;
}
