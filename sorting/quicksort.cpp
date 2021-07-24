#include "../structures/vector/vector.h"

#include <iostream>

std::size_t Partition(Vector<int> & v, int const p, int const r)
{
  int x = v[r - 1];
  int i = p - 1;

  for(std::size_t j = p; j < r; ++j)
    if (v[j] <= x)
      v.swap(j, ++i); 

  v.swap(x, i + 1); 

  return i;
}

void QuickSort(Vector<int> & v, int const p, int const r)
{
  if (p < r) {
    int q = Partition(v, p, r);
    QuickSort(v, p, q - 1);
    QuickSort(v, q + 1, r);
  }
}

int main(int argc, const char* args[])
{
  // Vector<int> v {8,3,4,7,1,2,6,5,9};
  // Vector<int> v {8,3,1,2};
  Vector<int> v {2,8,7,1,3,5,6,4};
  std::size_t len = v.length(); 

  QuickSort(v, 0, len);

  for (std::size_t i = 0; i < len; ++i)
    std::cout << v[i] << ' ';

  std::cout << '\n';
  return 0;
}
