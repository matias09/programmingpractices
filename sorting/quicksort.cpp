#include "../structures/vector/vector.h"

#include <iostream>

std::size_t Partition(Vector<int> & v, int const p, int const r)
{
  int x = v[r - 1];
  int i = p - 1;

  for(std::size_t j = p; j < r; ++j)
    if (v[j] <= x)
      v.swap(j, ++i); 

  v.swap(x, ++i); 
  return i;
}

void QuickSort(Vector<int> & v, int const p, int const r)
{
  if (p < r) {
    int q = Partition(v, p, r);
    QuickSort(v, p, q - 1);
    QuickSort(v, q, r);
  }
}

int main(int argc, const char* args[])
{
  Vector<int> v {2,8,7,1,3,5,6,4};
  std::size_t len = v.length(); 

  QuickSort(v, 0, len);
  for (std::size_t i = 0; i < len; ++i)
    std::cout << v[i] << ' ';

  std::cout << '\n';
  return 0;
}
