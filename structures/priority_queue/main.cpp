#include "max_priority_queue.h"

#include <iostream>

int main()
{
  MaxPriorityQueue pq;
  pq.Insert(16);
  pq.Insert(4);
  pq.Insert(10);
  pq.Insert(14);
  pq.Insert(7);
  pq.Insert(9);
  pq.Insert(3);
  pq.Insert(2);
  pq.Insert(8);
  pq.Insert(1);

  std::cout <<  pq.ExtractMax() << '\n';
  pq.Insert(100);

  auto const els = pq.GetUnderlineContainer();

  std::size_t len = els.length();
  for (std::size_t i = 0; i < len; ++i)
    std::cout << els[i] << ' ';

  std::cout << '\n';
  return 0;
}
