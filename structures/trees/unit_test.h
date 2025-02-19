// Cross Tests
template <typename T>
bool SizeCeroAtEmptyConstruction(T && c)
{
  return c.GetSize() == 0;
}

template <typename T>
bool SizeGreaterThanCeroAtConstructionWithInitializerList(T&& c)
{
  return c.GetSize() > 0;
}

template <typename T>
bool SizeEqualToOneAfterOneInsert(T&& c)
{
  c.Insert(1);
  return c.GetSize() == 1;
}

template <typename T>
bool SizeAfterThreeInsert(T&& c)
{
  c.Insert(1);
  c.Insert(2);
  c.Insert(3);

  return c.GetSize() == 3;
}

template <typename T>
bool TransplantRootLeftChildWithRootRightChild(T&& c)
{
  c.Insert(5);

  c.Insert(2);
  c.Insert(8);

  c.Transplant(c.GetRoot()->left, c.GetRoot()->right);

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

  return c.GetMinimum( c.GetRoot() )->value == 2;
}

template <typename T>
bool SizeBackToCeroAfterOneInsertAndOneErase(T&& c)
{
  c.Insert(1);
  c.Erase( c.GetRoot() );
  return c.GetSize() == 0;
}

template <typename T>
bool SizeCeroAfterInsertAndTwoErase(T&& c)
{
  c.Insert(1);
  c.Erase( c.GetRoot() );
  c.Erase( c.GetRoot() );

  return c.GetSize() == 0;
}

template <typename T>
bool TestHeightWithOneLevel(T&& c)
{
  // level 0
  c.Insert(10);

  // level 1
  c.Insert(5);
  c.Insert(15);

  return  c.GetRoot()->height == 1
       && c.GetRoot()->left->height == 0
       && c.GetRoot()->right->height == 0;
}

template <typename T>
bool TestHeightWithTwoLevels(T&& c)
{
  // level 0
  c.Insert(10);

  // level 1
  c.Insert(5);
  c.Insert(15);

  // level 2
  c.Insert(3);

  return  c.GetRoot()->height == 2
       && c.GetRoot()->left->height == 1
       && c.GetRoot()->right->height == 0;
}

template <typename T>
bool TestHeightWithThreeLevels(T&& c)
{
  // level 0
  c.Insert(10);

  // level 1
  c.Insert(5);
  c.Insert(15);

  // level 2
  c.Insert(3);
  c.Insert(13);

  // level 3
  c.Insert(2);

  return  c.GetRoot()->height == 2
       && c.GetRoot()->left->height == 1
       && c.GetRoot()->right->height == 1;
}

template <typename T>
bool LeftRotate(T&& c)
{
  // level 0
  c.Insert(10);

  // level 1
  c.Insert(5);
  c.Insert(15);

  // level 2
  c.Insert(13);
  c.Insert(17);

  c.LeftRotate( c.GetRoot() );

  return  c.GetRoot()->value == 15
       && c.GetRoot()->left->value == 10
       && c.GetRoot()->right->value == 17
       && c.GetRoot()->left->left->value == 5
       && c.GetRoot()->left->right->value == 13;
}

template <typename T>
bool RightRotate(T&& c)
{
  // level 0
  c.Insert(10);

  // level 1
  c.Insert(5);
  c.Insert(15);

  // level 2
  c.Insert(3);
  c.Insert(7);

  c.RightRotate( c.GetRoot() );

  return  c.GetRoot()->value == 5
       && c.GetRoot()->right->value == 10
       && c.GetRoot()->left->value == 3
       && c.GetRoot()->right->left->value == 7
       && c.GetRoot()->right->right->value == 15;
}

template <typename T>
bool LeftRotateLevel_2_Right(T&& c)
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
  c.Insert(4);

  c.Insert(6);
  c.Insert(8);

  c.Insert(12);
  c.Insert(14);

  c.Insert(16);
  c.Insert(50);

  c.LeftRotate( c.GetRoot()->right );

  return  c.GetRoot()->right->value == 17
       && c.GetRoot()->right->left->value == 15;
}

template <typename T>
bool RightRotateLevel_2_Right(T&& c)
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
  c.Insert(4);

  c.Insert(6);
  c.Insert(8);

  c.Insert(12);
  c.Insert(14);

  c.Insert(16);
  c.Insert(50);

  c.RightRotate( c.GetRoot()->right );

  return  c.GetRoot()->right->value == 13
       && c.GetRoot()->right->right->value == 15;
}

template <typename T>
bool LeftRotateLevel_1_Left(T&& c)
{
  // level 0
  c.Insert(5);

  // level 1
  c.Insert(2);

  // level 2
  c.Insert(3);

  c.LeftRotate( c.GetRoot()->left );

  return  c.GetRoot()->value == 5
       && c.GetRoot()->left->value == 3
       && c.GetRoot()->left->left->value == 2;
}

template <typename T>
bool RightRotateLevel_0_Root(T&& c)
{
  // level 0
  c.Insert(5);

  // level 1
  c.Insert(3);

  // level 2
  c.Insert(2);

  c.RightRotate( c.GetRoot() );

  return  c.GetRoot()->value == 3
       && c.GetRoot()->left->value == 2
       && c.GetRoot()->right->value == 5;
}

template <typename T>
bool BalanceRootLeftSecondLevel(T&& c)
{
  // level 0
  c.Insert(5);

  // // level 1
  c.Insert(3);

  // level 2
  c.Insert(2);

  return  c.GetRoot()->value == 3
       && c.GetRoot()->left->value == 2
       && c.GetRoot()->right->value == 5;
}

template <typename T>
bool InsertAndBalance_4_Levels(T&& c)
{
  // level 0
  c.Insert(11);

  // level 1
  c.Insert(2);
  c.Insert(14);

  // // level 2
  c.Insert(1);
  c.Insert(7);

  c.Insert(15);

  c.Insert(5);
  c.Insert(8);

  c.Insert(4);

  c.PrintInOrderTraversal( c.GetRoot() );

  return  c.GetRoot()->value == 7
       && c.GetRoot()->left->right->value == 5;
}
