#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "../vector/vector.h"

#include <iostream>
#include <initializer_list>

#include <math.h>

class PriorityQueue
{
public:
  explicit PriorityQueue() = default;
  explicit PriorityQueue(std::initializer_list<int> elements) 
    : ns_(elements)
  {
    std::size_t heap_size = ns_.length();
    for (std::size_t i = 0; i < heap_size; ++i)
      std::cout << ns_[i] << ' ';

    std::cout << '\n' << '\n';
  }

  ~PriorityQueue() {}

  void BuildMaxHeap()
  {
    std::size_t len = ns_.length() / 2;
    for (std::size_t i = 0; i < len; ++i)
      MaxHeapify(i);
  }

  void MaxHeapify(int const i, int j = 0)
  {
    if ( j == 20 ) return;

    std::size_t heap_size = ns_.length();
    for (std::size_t i = 0; i < heap_size; ++i)
      std::cout << ns_[i] << ' ';

    std::cout << '\n';

    int largest = 0;

    int l = Left(i);
    int r = Right(i);

    if (l <= heap_size && ns_[l] > ns_[i])
      largest = l;
    else
      largest = i;

    if (r <= heap_size && ns_[r] > ns_[largest])
        largest = r;

    if (largest != i) {
      ns_.swap(i, largest);
      MaxHeapify(largest, ++j);
    }
  }

  Vector<int> getnum() const { return ns_; }

private:
  int Parent(int const i) const { return std::floor(i / 2); }
  int Left(int const i) const { return i * 2; }
  int Right(int const i) const { return (i * 2) + 1; }

  Vector<int> ns_;
};

#endif // PRIORITY_QUEUE_H
