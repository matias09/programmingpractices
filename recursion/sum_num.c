#include <stdio.h>
#include <stdint.h>

uint16_t rec_sum_num(uint8_t const n)
{
  if ( n < 1 )  return 0;

  return rec_sum_num(n - 1) + n;
}

int main(int argc, char* args[])
{
  const uint8_t n = 5;

  uint8_t r = rec_sum_num(n); 
  printf("\t %d \n", r);

  return 0;
}
