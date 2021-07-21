#include <iostream>

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

  c.RightRotate();

  return (c[0] == 4
      &&  c[1] == 1
      &&  c[2] == 2
      &&  c[3] == 3);
}

