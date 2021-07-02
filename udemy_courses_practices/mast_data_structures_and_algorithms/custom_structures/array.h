#ifndef ARRAY_H
#define ARRAY_H

#include <initializer_list>
#include <iostream>

#include <stdlib.h>
#include <stdint.h>

template <typename T, std::size_t SIZE = 10>
class Array
{
public:
  explicit Array()
    : size_(SIZE) ,length_(0)
  {
    container = static_cast<T*>( malloc(sizeof(T) * SIZE) );
  }

  explicit Array(std::initializer_list<T> elements)
    : size_(SIZE) ,length_(0)
  {
    container = static_cast<T*>( malloc(sizeof(T) * SIZE) );

    for (auto const & e : elements)
      PushBack(e);
  }
 ~Array() { free(container); }

  bool PushBack(T const & e)
  {
    if (length_ == size_) {
      if (not ExpandContainerCapacity())
        return false;
    }

    container[length_++] = e;
    return true;
  }

  bool PopBack()
  {
    if (length_ < 1) {
        return false;
    }

    container[--length_] = 0;
    return true;
  }

  bool Insert(std::size_t const indx, T const & e)
  {
    if (indx >= length_) {
      return false;
    }

    if (length_ == size_) {
      if (not ExpandContainerCapacity())
        return false;
    }

    constexpr uint8_t INDEX_ON_PREV_POSITION = 1;
    for (std::size_t i = length_; i != indx; --i) {
      container[i] = container[i - INDEX_ON_PREV_POSITION];
    }
    container[indx] = e;

    ++length_;
    return true;
  }

  bool Erase(std::size_t const indx)
  {
    if (indx >= length_ || length_ == 0) {
      return false;
    }

    container[indx] = 0;
    --length_;

    constexpr uint8_t INDEX_ON_NEXT_POSITION = 1;
    for (std::size_t i = indx; i < length_; ++i) {
      container[i] = container[i + INDEX_ON_NEXT_POSITION];
    }

    return true;
  }

  bool Reverse()
  {
    if (length_ == 0) {
      return false;
    }

    constexpr uint8_t INDX_PREV_POS = 1;
    for (std::size_t i = 0, j = length_ - INDX_PREV_POS; i != j; ++i, --j) {
      swap(i, j);
    }

    return true;
  }

  bool LeftRotate()
  {
    if (length_ == 0) {
      return false;
    }

    constexpr uint8_t INDX_NEXT_POS = 1;
    for (std::size_t i = 0, j = i + INDX_NEXT_POS; j < length_; ++i, ++j) {
      swap(i, j);
    }
    return true;
  }

  bool RightRotate()
  {
    if (length_ == 0) {
      return false;
    }

    constexpr uint8_t INDX_PREV_ONE_POS = 1;
    for (std::size_t j = length_ - INDX_PREV_ONE_POS
                   , i = j - INDX_PREV_ONE_POS 
         ; j > 0; --i, --j) 
    {
      swap(i, j);
    }

    return true;
  }

  std::size_t size() const { return size_; }
  std::size_t length() const { return length_; }

  const T& operator[] (int const i) const { return container[i]; }
  T& operator[] (int const i) { return container[i]; }

private:
  bool ExpandContainerCapacity()
  {
    static std::size_t increment_unit = 1;

    const std::size_t NEW_SIZE = (SIZE * (++increment_unit));
    T* tmp = static_cast<T*>( malloc(sizeof(T) * NEW_SIZE) );

    for (std::size_t i = 0; i < size_; ++i) {
      tmp[i] = container[i];
    }

    free(container);
    container = tmp;

    size_ = NEW_SIZE;
    return true;
  }

  void swap(std::size_t const i, std::size_t const j)
  {
    T tmp = container[i];
    container[i] = container[j];
    container[j] = tmp;
  }

  T* container;
  std::size_t size_;
  std::size_t length_;
};

#endif // ARRAY_H

// Unit Test
template <typename T>
void ShowContainer(T const & c)
{
  std::size_t al = c.length();
  for (std::size_t i = 0; i < al; ++i)
    std::cout << c[i] << ' ';
}

template <typename T>
bool LengthCeroAtEmptyConstruction(T && c)
{
  return c.length() == 0;
}

template <typename T>
bool LengthGreaterThanCeroAtConstructionWithInitializerList(T&& c)
{
  return c.length() > 0;
}

template <typename T>
bool LengthEqualToOneAfterOnePushBack(T&& c)
{
  c.PushBack(1);
  return c.length() == 1;
}

template <typename T>
bool LengthBackToCeroAfterOnePushAndOnePop(T&& c)
{
  c.PushBack(1);
  c.PopBack();
  return c.length() == 0;
}

template <typename T>
bool ErrorAfterOnePushAndOnePop(T&& c)
{
  c.PushBack(1);
  c.PopBack();
  c.PopBack();

  return c.length() == false;
}

template <typename T>
bool LengthAfterThreePush(T&& c)
{
  c.PushBack(1);
  c.PushBack(2);
  c.PushBack(3);

  return c.length() == 3;
}

template <typename T>
bool ResizeContainerToDoubleCapacityAfterPushTheLimits(T&& c)
{
  c.PushBack(1);
  c.PushBack(2);
  c.PushBack(3);

  c.PushBack(4);

  return (c.size() == 6 && c.length() == 4);
}

template <typename T>
bool InsertAtIndex_0_OnEmptyContainer(T&& c)
{
  int const n = 3;
  return (c.Insert(0, n) == false &&  c.length() == 0);
}

template <typename T>
bool InsertAtIndex_Minus_1(T&& c)
{
  int const n = 2;

  c.PushBack(1);
  c.PushBack(3);
  c.PushBack(4);

  return (c.Insert(-1, n) == false);
}

template <typename T>
bool InsertAtIndex_1_OnContainerWithLength_3(T&& c)
{
  int const n = 2;

  c.PushBack(1);
  c.PushBack(3);
  c.PushBack(4);

  c.Insert(1, n);

  std::size_t l = c.length();
  for (std::size_t i = 0; i < l; ++i) {
    if (c[i] != (i + 1)) {
      return false;
    }
  }

  return true;
}

template <typename T>
bool InsertAtIndex_8_OnFullContainer(T&& c)
{
  int const n = 9;

  std::size_t limit = c.size() + 1;
  for (std::size_t i = 0; i < limit;) {
    if (++i == n) {
      continue;
    }
    c.PushBack(i);
  }

  c.Insert(8, n);

  limit = c.length();
  for (std::size_t i = 0; i < limit; ++i) {
    if (c[i] != (i + 1)) {
      return false;
    }
  }

  return true;
}

template <typename T>
bool InsertAtIndex_0_OnFullContainer(T&& c)
{
  int const n = 1;

  std::size_t limit = c.size() + 1;
  for (std::size_t i = 0; i < limit;) {
    if (++i == n) {
      continue;
    }
    c.PushBack(i);
  }

  c.Insert(0, n);

  limit = c.length();
  for (std::size_t i = 0; i < limit; ++i) {
    if (c[i] != (i + 1)) {
      return false;
    }
  }

  return true;
}

template <typename T>
bool InsertAtIndex_5_OnAlmostFullContainer(T&& c)
{
  int const n = 6;

  std::size_t limit = c.size();
  for (std::size_t i = 0; i < limit;) {
    if (++i == n) {
      continue;
    }
    c.PushBack(i);
  }

  c.Insert(5, n);

  limit = c.length();
  for (std::size_t i = 0; i < limit; ++i) {
    if (c[i] != (i + 1)) {
      return false;
    }
  }

  return true;
}

template <typename T>
bool EraseAtIndex_0_OnEmptyContainer(T&& c)
{
  int const i = 0;
  return (c.Erase(i) == false);
}

template <typename T>
bool EraseAtIndex_0_OnContainerWithOneElement(T&& c)
{
  constexpr uint8_t n = 1;
  constexpr uint8_t i = 0;

  c.PushBack(n);
  c.Erase(i);

  return (c.length() == 0);
}

template <typename T>
bool EraseAtIndex_0_OnContainerWithTwoElement(T&& c)
{
  constexpr uint8_t n = 1;
  constexpr uint8_t i = 0;

  c.PushBack(n);
  c.PushBack(n + 1);
  c.Erase(i);

  return (c[0] == 2 && c.length() == 1);
}

template <typename T>
bool EraseAtLastIndexOnFullContainer(T&& c)
{
  std::size_t limit = c.size();
  for (std::size_t i = 0; i < limit; ++i) {
    c.PushBack(i);
  }

  const uint8_t indx = c.length() - 1;
  c.Erase(indx);

  return (c[indx - 1] == (c.length() - 1) && c.length() == c.size() - 1);
}

template <typename T>
bool ReverseEmptyContainer(T&& c)
{
  return (c.Reverse() == false);
}

template <typename T>
bool ReverseContainerFrom_1_to_3(T&& c)
{
  constexpr uint8_t limit = 4;
  for (std::size_t i = 1; i < limit; ++i) {
    c.PushBack(i);
  }

  c.Reverse();

  return (c[0] == 3
      &&  c[1] == 2
      &&  c[2] == 1);
}

template <typename T>
bool LeftRotateEmptyContainer(T&& c)
{
  return (c.LeftRotate() == false);
}

template <typename T>
bool LeftRotateContainerFrom_1_to_5(T&& c)
{
  constexpr uint8_t limit = 5;
  for (std::size_t i = 1; i < limit; ++i) {
    c.PushBack(i);
  }

  c.LeftRotate();

  return (c[0] == 2
      &&  c[1] == 3
      &&  c[2] == 4
      &&  c[3] == 1);
}

template <typename T>
bool RigthRotateEmptyContainer(T&& c)
{
  return (c.RightRotate() == false);
}

template <typename T>
bool RightRotateContainerFrom_1_to_5(T&& c)
{
  constexpr uint8_t limit = 5;
  for (std::size_t i = 1; i < limit; ++i) {
    c.PushBack(i);
  }

  ShowContainer(c);
  c.RightRotate();
  ShowContainer(c);

  return (c[0] == 4
      &&  c[1] == 1
      &&  c[2] == 2
      &&  c[3] == 3);
}
