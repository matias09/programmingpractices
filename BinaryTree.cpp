#include <iostream>
#include <stdexcept>

// Own Classes
#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
  std::cout << " \n Building BinaryTree . . . \n";
  mCountGreatestNumbers = 0;
  mCountLowestNumbers = 0;
  mCount = 0;
  mHeadNode = nullptr;
}

BinaryTree::~BinaryTree()
{
  std::cout << " \n Releasing BinaryTree . . . \n";
}

void BinaryTree::ShowElements()
{
  if (mHeadNode != nullptr)
  {
    std::cout << "Nodes Values : ";
    ShowNode(mHeadNode);
  }
  else
  {
    std::cout << "Empty Container";
  }
}

void BinaryTree::ShowNode(Node* node)
{
  std::cout << node->n << " ";
  if (node->mLeftDirectionTaken == false)
  {
    if (node->mLower != nullptr)
    {
      ShowNode(node->mLower);
    }
    node->mLeftDirectionTaken = true;
  }

  if (node->mRightDirectionTaken == false)
  {
    if (node->mGreater != nullptr)
    {
      ShowNode(node->mGreater);
    }
    node->mRightDirectionTaken = true;
  }
    node->mLeftDirectionTaken = false;
    node->mRightDirectionTaken = false;
}

void BinaryTree::Insert(const int n)
{
  try
  {
    if (mHeadNode == nullptr)
    {
      mHeadNode = new Node(n);
    }
    else
    {
      unsigned int levelCounter = 1;
      SaveNode(mHeadNode, n, levelCounter);

      if (n > mHeadNode->n)
      {
        if (levelCounter > mCountGreatestNumbers)
        {
          mCountGreatestNumbers = levelCounter;
        }
      }
      else
      {
        if (levelCounter > mCountLowestNumbers)
        {
          mCountLowestNumbers = levelCounter;
        }
      }
    }

    // Increase total number count
    ++mCount;

    if ((mCountGreatestNumbers - mCountLowestNumbers) == 2 || (mCountLowestNumbers - mCountGreatestNumbers) == 2)
    {
      std::cout << "A call to BalanceTree will be trigger,";
      std::cout << "but when be coded :) . \n Still as homework and inProgress . . .\n\n";
    }
    else
    {
      std::cout << "If a don't mistake in the previous check, so the tree is balanced . . .\n\n";
    }
  }
  catch(std::runtime_error& e)
  {
    std::cout << "Exception Catched . . . \n";
    std::cout << "Man, la cagaste guardando un puntero \n";
  }
}

void BinaryTree::SaveNode(Node* node, const int n, unsigned int& level)
{
  if (n > node->n)
  {
    if (node->mGreater == nullptr)
    {
      node->mGreater = new Node(n);
    }
    else
    {
      ++level;
      SaveNode(node->mGreater, n, level);
    }
  }
  else
  {
    if (node->mLower == nullptr)
    {
      node->mLower = new Node(n);
    }
    else
    {
      ++level;
      SaveNode(node->mLower, n, level);
    }
  }
}

void BinaryTree::ReleaseNodes()
{
}
