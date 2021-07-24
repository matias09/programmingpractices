#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>

#include <stdint.h>

template <typename T, std::size_t SIZE = 10>
class Vector
{
public:
  explicit Vector()
    : size_(SIZE) ,length_(0)
  {
    container = new T[SIZE];
  }

  explicit Vector(std::initializer_list<T> elements)
    : size_(SIZE) ,length_(0)
  {
    container = new T[SIZE];

    for (auto const & e : elements)
      PushBack(e);
  }

  Vector(Vector const & rh)
  {
    this->size_ = rh.size();
    this->length_ = rh.length();
    this->container = new T[this->size_];

    std::size_t len = rh.length();
    for (std::size_t i = 0; i < len; ++i)
      this->container[i] = rh[i];
  }

 ~Vector() 
 { 
   if (container != nullptr)
     delete[] container; 

   container = nullptr;
 }

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
    if (length_ < 1)
        return false;

    container[--length_] = 0;
    return true;
  }

  bool Insert(std::size_t const indx, T const & e)
  {
    if (indx >= length_)
      return false;

    if (length_ == size_) {
      if (not ExpandContainerCapacity())
        return false;
    }

    constexpr const uint8_t INDEX_ON_PREV_POSITION = 1;
    for (std::size_t i = length_; i != indx; --i)
      container[i] = container[i - INDEX_ON_PREV_POSITION];

    container[indx] = e;

    ++length_;
    return true;
  }

  bool Erase(std::size_t const indx)
  {
    if (indx >= length_ || length_ == 0)
      return false;

    container[indx] = 0;
    --length_;

    constexpr const uint8_t INDEX_ON_NEXT_POSITION = 1;
    for (std::size_t i = indx; i < length_; ++i)
      container[i] = container[i + INDEX_ON_NEXT_POSITION];

    return true;
  }

  bool Reverse()
  {
    if (length_ == 0)
      return false;

    constexpr const uint8_t INDX_PREV_POS = 1;
    for (std::size_t i = 0, j = length_ - INDX_PREV_POS; i != j; ++i, --j)
      swap(i, j);

    return true;
  }

  bool LeftRotate()
  {
    if (length_ == 0)
      return false;

    constexpr const uint8_t INDX_NEXT_POS = 1;
    for (std::size_t i = 0, j = i + INDX_NEXT_POS; j < length_; ++i, ++j)
      swap(i, j);

    return true;
  }

  bool RightRotate()
  {
    if (length_ == 0)
      return false;

    constexpr const uint8_t INDX_PREV_ONE_POS = 1;
    for (std::size_t j = length_ - INDX_PREV_ONE_POS
                   , i = j - INDX_PREV_ONE_POS
         ; j > 0; --i, --j)
    {
      swap(i, j);
    }

    return true;
  }

  void swap(std::size_t const i, std::size_t const j)
  {
    T tmp = container[i];
    container[i] = container[j];
    container[j] = tmp;
  }

  std::size_t size() const { return size_; }
  std::size_t length() const { return length_; }

  const T& operator[] (int const i) const { return container[i]; }
  T& operator[] (int const i) { return container[i]; }

private:
  bool ExpandContainerCapacity()
  {
    static std::size_t increment_unit = 0;

    const std::size_t NEW_SIZE = (SIZE * (++increment_unit));
    T* tmp = new T[NEW_SIZE];

    for (std::size_t i = 0; i < size_; ++i)
      tmp[i] = container[i];

    delete[] container;
    container = tmp;

    size_ = NEW_SIZE;
    return true;
  }

  T* container;
  std::size_t size_;
  std::size_t length_;
};

#endif // VECTOR_H
