#ifndef  PRIORITY_QUEUE_H
#define  PRIORITY_QUEUE_H

#include "vector.h"

#include <iostream>
#include <initializer_list>

class PriorityQueue
{
public:
  explicit PriorityQueue() = default;
  explicit PriorityQueue(std::initializer_list<int> elements) 
  {
    for (auto const & e : elements) 
      numbers_.PushBack(e);
  }

 ~PriorityQueue() {}

 void PrintElements() const 
 {
   std::size_t len = numbers_.length();
   for (std::size_t i = 0; i < len; ++i)
     std::cout << numbers_[i] << ' ';
 }

private:
 Vector<int> numbers_;
};

#endif // PRIORITY_QUEUE_H
