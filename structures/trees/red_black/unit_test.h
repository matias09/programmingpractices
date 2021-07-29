template <typename T>
bool SizeCeroAtEmptyConstruction(T && c)
{
  return c.Size() == 0;
}

template <typename T>
bool SizeGreaterThanCeroAtConstructionWithInitializerList(T&& c)
{
  return c.Size() > 0;
}

template <typename T>
bool SizeEqualToOneAfterOneInsert(T&& c)
{
  c.Insert(1);
  return c.Size() == 1;
}

template <typename T>
bool TransplantRootLeftChildWithRootRightChild(T&& c)
{
  c.Insert(5);

  c.Insert(2);
  c.Insert(8);

  c.Trasplant(c.GetRoot()->left, c.GetRoot()->right);

  return c.GetRoot()->left->value  == 8
      && c.GetRoot()->right->value == 2;
}

template <typename T>
bool GetMinimunNodeStartingFromRoot(T&& c)
{
  // level 0
  c.Insert(10);

  // level 1
  c.Insert(5);
  c.Insert(15);

  // level 2
  c.Insert(3);
  c.Insert(7);

  c.Insert(13);
  c.Insert(17);

  // level 3
  c.Insert(2);
  c.Insert(6);

  return c.Minimum( c.GetRoot() )->value == 2;
}

template <typename T>
bool SizeBackToCeroAfterOneInsertAndOneErase(T&& c)
{
  c.Insert(1);
  c.Erase();
  return c.Size() == 0;
}

template <typename T>
bool SizeAfterThreeInsert(T&& c)
{
  c.Insert(1);
  c.Insert(2);
  c.Insert(3);

  return c.Size() == 3;
}

template <typename T>
bool ErrorAfterOneInsertAndOneErase(T&& c)
{
  c.Insert(1);
  c.Erase();
  c.Erase();

  return c.Size() == false;
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

  for (std::size_t i = 0; i <= n; ++i)
    c.Insert(i + 1);

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

  return (c.Size() == (n - 1));
}

template <typename T>
bool EraseAtIndex_3_BetweenOriginAndEnd(T&& c)
{
  constexpr int const n   = 5;
  constexpr int const idx = 3;

  for (std::size_t i = 0; i < n; ++i)
    c.Insert(i + 1);

  c.Erase(idx);

  return (c.At(idx)->value == 1 && c.Size() == (n - 1));
}

template <typename T>
bool EraseAtIndex_5_AtTheEnd(T&& c)
{
  constexpr int const n   = 6;
  constexpr int const idx = 5;

  for (std::size_t i = 0; i < n; ++i)
    c.Insert(i + 1);

  c.Erase(idx);

  return (c.At(idx - 1)->value == 2 && c.Size() == (n - 1));
}
