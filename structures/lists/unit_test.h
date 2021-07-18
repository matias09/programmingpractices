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
  c.Insert(1);
  return c.length() == 1;
}

template <typename T>
bool LengthBackToCeroAfterOnePushAndOnePop(T&& c)
{
  c.Insert(1);
  c.Erase();
  return c.length() == 0;
}

template <typename T>
bool LengthAfterThreePush(T&& c)
{
  c.Insert(1);
  c.Insert(2);
  c.Insert(3);

  return c.length() == 3;
}

template <typename T>
bool ErrorAfterOnePushAndOnePop(T&& c)
{
  c.Insert(1);
  c.Erase();
  c.Erase();

  return c.length() == false;
}

template <typename T>
bool InsertAtIndex_0_AtTheBeggining(T&& c)
{
  int const n   = 6;
  int const idx = 0;

  for (std::size_t i = 0; i < n;) {
    if (++i == n) {
      continue;
    }
    c.Insert(i);
  }
  c.Insert(n, idx);

  return (c.At(idx)->value == n);
}

template <typename T>
bool InsertAtIndex_3_InTheMiddle(T&& c)
{
  int const n   = 6;
  int const idx = 3;

  for (std::size_t i = 0; i < n;) {
    if (++i == n) {
      continue;
    }
    c.Insert(i);
  }
  c.Insert(n, idx);

  return (c.At(idx)->value == n);
}

template <typename T>
bool InsertAtIndex_5_AtTheEnd(T&& c)
{
  int const n   = 6;
  int const idx = 5;

  for (std::size_t i = 0; i < n;) {
    if (++i == n)
      continue;

    c.Insert(i);
  }
  c.Insert(n, idx);

  return (c.At(idx)->value == n);
}

template <typename T>
bool EraseAtIndex_0_WithNoElements(T&& c)
{
  int const idx = 0;
  return (c.Erase(idx) == false);
}

template <typename T>
bool EraseAtIndex_0_WithElements(T&& c)
{
  constexpr int const n = 1;
  constexpr int const idx = 0;

  c.Insert(n);
  c.Erase(idx);

  return (c.length() == (n - 1));
}

template <typename T>
bool EraseAtIndex_3_BetweenOriginAndEnd(T&& c)
{
  constexpr int const n   = 5;
  constexpr int const idx = 3;

  for (std::size_t i = 0; i < n; ++i)
    c.Insert(i + 1);

  c.Erase(idx);

  return (c.At(idx)->value == 1 && c.length() == (n - 1));
}

template <typename T>
bool EraseAtIndex_5_AtTheEnd(T&& c)
{
  constexpr int const n   = 6;
  constexpr int const idx = 5;

  for (std::size_t i = 0; i < n; ++i)
    c.Insert(i + 1);

  c.Erase(idx);

  return (c.At(idx - 1)->value == 2 && c.length() == (n - 1));
}
