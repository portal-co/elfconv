#include <stdio.h>
#include <stdlib.h>

int isPrime(int n) {
  if (n <= 1)
    return 0;
  if (n <= 3)
    return 1;

  if (n % 2 == 0 || n % 3 == 0)
    return 0;

  for (int i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0)
      return 0;
  }
  return 1;
}

long findMaxPrimeBelow(int n) {
  long res = 0;
  for (int i = 0; i <= n; i++) {
    if (isPrime(i))
      res = i;
  }
  return res;
}

int main() {
  long number = 10000000;
  int digit_num = 7;
  long maxPrime = findMaxPrimeBelow(number);
  char moziretu[100];
  for (int i = 10; maxPrime > i / 10; i *= 10) {
    if (digit_num == 0) {
      printf("digit num error\n");
      exit(EXIT_FAILURE);
    }
    long amari = maxPrime % i;
    moziretu[--digit_num] = '0' + amari / (i / 10);
  }
  moziretu[7] = 0;
  moziretu[8] = '\n';
  printf("max prime: %s\n", moziretu);

  return 0;
}
