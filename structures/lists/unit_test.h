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

