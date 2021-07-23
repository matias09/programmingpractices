#ifndef MAX_PRIORITY_QUEUE_H
#define MAX_PRIORITY_QUEUE_H

#include "../vector/vector.h"

#include <initializer_list>

#include <math.h>

class MaxPriorityQueue
{
public:
  explicit MaxPriorityQueue() = default;
  explicit MaxPriorityQueue(std::initializer_list<int> elements) 
    : ns_(elements)
  {
    SetHeapSize( ns_.length() - 1 );
    BuildMaxHeap();
  }

  ~MaxPriorityQueue() {}

  void BuildMaxHeap()
  {
    std::size_t len = ns_.length() / 2;
    for (int i = len; i > -1 ; --i)
      MaxHeapify(i);
  }

  void MaxHeapify(int const i)
  {
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
      MaxHeapify(largest);
    }
  }

  void SetHeapSize(std::size_t const size) { heap_size = size; }

  Vector<int> GetUnderlineContainer() const { return ns_; }

private:
  int Parent(int const i) const { return std::floor(i / 2); }
  int Left(int const i) const { return (i == 0) ? 1 : (i * 2) + 1; }
  int Right(int const i) const { return (i == 0) ? 2 : (i * 2) + 2; }

  Vector<int> ns_;
  std::size_t heap_size;
};

#endif // MAX_PRIORITY_QUEUE_H
