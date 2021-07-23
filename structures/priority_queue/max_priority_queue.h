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
    heap_size = ns_.length() - 1;
    BuildMaxHeap();
  }

  ~MaxPriorityQueue() {}

  void Insert(int const e) { ns_.PushBack(e); }
  void IncreaseKey(int const k, int const v) {}

  int ExtractMax() 
  {  
    if (ns_.length() < 1)
      return 0;

    int max = ns_[0];
    ns_[0] = ns_[ ns_.length() - 1 ];
    ns_.PopBack();

    heap_size = ns_.length() - 1;
    MaxHeapify(0);

    return max;
  }
  int Maximum() const { return ns_[0]; }

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

  int Length() const { return ns_.length(); }
  Vector<int> GetUnderlineContainer() const { return ns_; }

private:
  int Parent(int const i) const { return std::floor(i / 2); }
  int Left(int const i) const { return (i == 0) ? 1 : (i * 2) + 1; }
  int Right(int const i) const { return (i == 0) ? 2 : (i * 2) + 2; }

  Vector<int> ns_;
  std::size_t heap_size;
};

#endif // MAX_PRIORITY_QUEUE_H
