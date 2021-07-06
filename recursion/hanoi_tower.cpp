#include <stdio.h>
#include <stdint.h>

void hanoi_tower(const char s, const char d, const char e, const int n)
{
  if (n < 1) 
    return;

  hanoi_tower(s, e, d, n - 1);
  printf("\t Move Disk %d from %c to %c \n", n, s, d);
  hanoi_tower(e, d, s, n - 1);
}

int main(int argc, char* args[])
{
  const uint8_t n = 3;

  printf("-- Disk Movements : \n");
  hanoi_tower('S', 'D', 'E', n);

  printf("\n");
  return 0;
}
