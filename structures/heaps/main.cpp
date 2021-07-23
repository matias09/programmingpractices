#include "max_heap.h"

#include <iostream>

int main()
{
  MaxHeap mh{16,4,10,14,7,9,3,2,8,1};

  auto const els = mh.GetUnderlineContainer();

  std::size_t len = els.length();
  for (std::size_t i = 0; i < len; ++i)
    std::cout << els[i] << ' ';

  mh.HeapSort();
  std::cout << '\n' << '\n';

  auto const els2 = mh.GetUnderlineContainer();
  for (std::size_t i = 0; i < len; ++i)
    std::cout << els2[i] << ' ';

  std::cout << '\n' << '\n';
  return 0;
}
