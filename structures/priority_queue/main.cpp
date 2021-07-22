#include "priority_queue.h"
#include <iostream>

int main()
{
  PriorityQueue pq{8,2,0,4,1,3};
  pq.PrintElements();

  std::cout << '\n';
  return 0;
}
