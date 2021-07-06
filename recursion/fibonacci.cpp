#include <stdio.h>
#include <stdint.h>
#include <string.h>

uint32_t rec_fibonacci(uint8_t const n)
{
  if (n < 3)
    return 1;
  else
    return rec_fibonacci(n - 1) + rec_fibonacci(n - 2);
}

uint32_t rec_memo_fibonacci(uint8_t const n, uint32_t cache[])
{
  if (n < 3)
    return 1;

  if (cache[n - 1] == 0)
    cache[n - 1] = rec_memo_fibonacci(n - 1, cache) 
                 + rec_memo_fibonacci(n - 2, cache);

  return cache[n - 1];
}

uint32_t ite_fibonacci(uint8_t const n)
{
  if (n < 3)
    return 1;

  uint32_t a = 0;
  uint32_t r = 1;

  for (uint8_t i = 2; i < n; ++i) {
    a = r - a;
    r = r + a;
  }

  return r;
}

int main(int argc, char** args)
{
  const uint8_t  n = 8;

  printf("-- Fib number for %d : %d \n", n, rec_fibonacci(n));

  uint32_t * cache = new uint32_t[n];
  memset(cache, 0, sizeof(uint32_t) * n); 

  printf("-- MEMO Fib number for %d : %d \n"
       , n, rec_memo_fibonacci(n, cache)); 

  printf("-- ITE Fib number for %d : %d \n", n, ite_fibonacci(n));

  delete[] cache;
  return 0;
}
