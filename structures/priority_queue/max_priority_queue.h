#ifndef MAX_PRIORITY_QUEUE_H
#define MAX_PRIORITY_QUEUE_H

#include "../vector/vector.h"

#include <initializer_list>

#include <math.h>

class MaxPriorityQueue
{
public:
  explicit MaxPriorityQueue()
   : heap_size(0) {}

  explicit MaxPriorityQueue(std::initializer_list<int> elements)
    : ns_(elements)
  {
    heap_size = ns_.length();
    BuildMaxHeap();
  }

  ~MaxPriorityQueue() {}

  void Insert(int const k)
  {
    ++heap_size;
    ns_.PushBack(-1);
    IncreaseKey(heap_size - 1, k);
  }

  void IncreaseKey(int i, int const k)
  {
    if (k < ns_[i])
      return;

    ns_[i] = k;
    while (i > 0 && ns_[ Parent(i) ] < ns_[i]) {
      ns_.swap(i, Parent(i));
      i = Parent(i);
    }
  }

  int ExtractMax()
  {
    if (heap_size < 1)
      return 0;

    int max = ns_[ROOT_ELEMENT];
    ns_[ROOT_ELEMENT] = ns_[ heap_size - 1 ];
    ns_.PopBack();

    --heap_size;
    MaxHeapify(ROOT_ELEMENT);

    return max;
  }
  int Maximum() const { return ns_[ROOT_ELEMENT]; }

  void BuildMaxHeap()
  {
    std::size_t len = heap_size / 2;
    for (int i = len; i > -1 ; --i)
      MaxHeapify(i);
  }

  void MaxHeapify(int const i)
  {
    int largest = 0;

    int l = Left(i);
    int r = Right(i);

    if (l <= (heap_size - 1) && ns_[l] > ns_[i])
      largest = l;
    else
      largest = i;

    if (r <= (heap_size - 1) && ns_[r] > ns_[largest])
        largest = r;

    if (largest != i) {
      ns_.swap(i, largest);
      MaxHeapify(largest);
    }
  }

  Vector<int> GetUnderlineContainer() const { return ns_; }

private:
  int Parent(int const i) const
  {
    return ((i % 2) == 0) ? std::floor(i / 2) - 1 : std::floor(i / 2);
  }
  int Left(int const i) const { return (i == 0) ? 1 : (i * 2) + 1; }
  int Right(int const i) const { return (i == 0) ? 2 : (i * 2) + 2; }

  static constexpr const std::size_t ROOT_ELEMENT = 0;

  Vector<int> ns_;
  std::size_t heap_size;
};

#endif // MAX_PRIORITY_QUEUE_H
