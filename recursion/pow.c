#include <stdio.h>
#include <stdint.h>

uint16_t rec_pow_1(uint8_t const m, uint8_t const n)
{
  if ( n < 1 )  return 1;
  return rec_pow_1(m, n - 1) * m;
}

uint16_t rec_pow_2(uint8_t const m, uint8_t const n)
{
  if ( n < 1 )  return 1;

  if ( (n % 2) == 0) {
    return rec_pow_2(m*m, ( n/2 ));
  } else {
    return rec_pow_2(m*m, ( (n - 1) / 2 )) * m;
  }
}

int main(int argc, char* args[])
{
  const uint8_t n = 2;
  const uint8_t e = 5;

  uint8_t r = rec_pow_1(n, e); 
  printf("\t rec_pow_1(%d, %d) = %d \n", n, e, r);

  r = rec_pow_2(n, e); 
  printf("\t rec_pow_2(%d, %d) = %d \n", n, e, r);

  return 0;
}
