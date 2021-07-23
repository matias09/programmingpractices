#include "priority_queue.h"
#include <iostream>

int main()
{
  // another example written
  // PriorityQueue pq{7,2,9,4,1,5,30};
  PriorityQueue pq{16,4,10,14,7,9,3,2,8,1};

  auto const els = pq.GetUnderlineContainer();

  std::size_t len = els.length();
  for (std::size_t i = 0; i < len; ++i)
    std::cout << els[i] << ' ';

  pq.HeapSort();
  std::cout << '\n' << '\n';

  auto const els2 = pq.GetUnderlineContainer();
  for (std::size_t i = 0; i < len; ++i)
    std::cout << els2[i] << ' ';

  std::cout << '\n' << '\n';
  return 0;
}
