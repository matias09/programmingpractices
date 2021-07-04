#include <stdio.h>
#include <stdint.h>

uint16_t rec_nested(uint8_t const n)
{
  if ( n > 100 ) {
    return n - 10;
  }

  return rec_nested( rec_nested(n + 11) );
}

int main(int argc, char* args[])
{
  const uint8_t n = 30;

  uint8_t r = rec_nested(n); 
  printf("\t %d \n", r);

  return 0;
}
