#include <stdio.h>
#include <stdint.h>

uint16_t ite_factorial(uint8_t const n)
{
  if (n < 1) 
    return 1;

  uint16_t factorial = 1;

  for(uint8_t i = n; i > 0; --i) {
    factorial *= i;
  }

  return factorial;
}

uint16_t rec_factorial(uint8_t const n)
{
  if (n < 1)
    return 1;

  return n * rec_factorial(n - 1);
}
uint16_t imp_rec_factorial(uint8_t const n, uint16_t r)
{
  if (n < 1)
    return 1;

  return imp_rec_factorial(n - 1, r * n);
}

int main(int argc, char* args[])
{
  const uint8_t n = 3;

  uint16_t f = ite_factorial(n);
  printf("\t ite factorial of %d = %d \n", n, f);

  f = rec_factorial(n);
  printf("\t rec factorial of %d = %d \n", n, f);

  f = imp_rec_factorial(n, 1);
  printf("\t imp rec factorial of %d = %d \n", n, f);

  return 0;
}
