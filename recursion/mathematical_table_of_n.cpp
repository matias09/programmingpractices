#include <stdio.h>
#include <stdint.h>

void ite_n_mathematical_table(uint8_t const n)
{
  for(uint8_t i = 1; i < n; ++i) {
    printf("%d * %d = %d\n", n, i, (n*i));
  }
}

void rec_n_mathematical_table(uint8_t const n, uint16_t i)
{
  if (i == n)  return;

  printf("%d * %d = %d\n", n, i, (n * i) );
  rec_n_mathematical_table(n, ++i);
}

int main(int argc, char* args[])
{
  const uint8_t n = 3;

  printf("-- Iterative: \n");
  ite_n_mathematical_table(n);

  printf("\n");
  printf("-- Recursive: \n");
  rec_n_mathematical_table(n, 1);
  return 0;
}
