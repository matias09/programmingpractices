#include <stdio.h>
#include <stdint.h>

uint16_t ite_sum_natural_num(uint16_t const n)
{
  if ( n < 1 )  
    return 0;

  uint16_t r = 0;
  for (uint16_t i = 0; i < n; ++i) {
    r += i + 1;
  }

  return r;
}

uint16_t rec_sum_natural_num(uint16_t const n)
{
  if ( n < 1 )  
    return 0;

  return rec_sum_natural_num(n - 1) + n;
}

int main(int argc, char* args[])
{
  const uint8_t n = 5;

  uint8_t r = rec_sum_natural_num(n); 
  printf("\t rec_sum_natural_num(%d) : %d \n", n, r);

  r = ite_sum_natural_num(n); 
  printf("\t ite_sum_natural_num(%d) : %d \n", n, r);

  return 0;
}
