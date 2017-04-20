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

// This will be change to return a Json string
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

    // Evaluate if the Tree is balanced
    if ((mCountGreatestNumbers - mCountLowestNumbers) == 2 || (mCountLowestNumbers - mCountGreatestNumbers) == 2)
    {
    //  std::cout << "A call to ProcessVerticalBalance will be trigger,";
    //  std::cout << "but when be coded :) . \n Still as homework and inProgress . . .\n\n";

      // This Doesn't work yet. But Will be fix during the week
       ProcessVerticalBalance(); // Working Progress . . .
    }
    else
    {
   //   std::cout << "If a don't mistake in the previous check, so the tree is balanced . . .\n\n";
    }
  }
  catch(std::runtime_error& e)
  {
    std::cout << "Exception Catched . . . \n";
    std::cout << "Trying to save a Node \n";
  }
}

Node* BinaryTree::Find(const int n)
{
  Node* tmpNodeToSet = FindNode(*(mHeadNode), n);
  return tmpNodeToSet;
}

bool BinaryTree::Remove(const int n)
{
  return RemoveNode(mHeadNode, *(mHeadNode), n);
}

// --------------------- Private Methods ---------------------- //

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


// Starts Vertical Balance Methods
void BinaryTree::ProcessVerticalBalance() // Working Progress . . .
{
  Node* tmpAverageNode = GetAverageNode();

  std::cout << "\n\n/---------------------------------------------/ \n";
  std::cout << "The Average selected Node is : " << tmpAverageNode->n << "\n";

  MakeVerticalChanges(tmpAverageNode);
}

void BinaryTree::MakeVerticalChanges(Node* node) // Working Progress . . .
{
  std::cout << "\n\n/---------------------------------------------/ \n";
  std::cout << "\t . . . BinaryTree::MakeVerticalChanges       . . . \n";
  std::cout << "\t . . . I'm Close to be Coded DON'T HESITATE  . . . \n";
  std::cout << "/---------------------------------------------/ \n";
}

Node* BinaryTree::GetAverageNode() // Working Progress . . .
{
  // This Node will become in the new head Node
  // and from he the Tree will be reconstruct
  Node* tmpGreatestAverageNode = nullptr;
  Node* tmpLowestAverageNode = nullptr;

  // The numbers could be all negatives. You don't have to put "unsigned"
  unsigned int total = 0;
  int average = 0;

  // Distance between the average number and first node from
  // the greatest side
  unsigned int disBettAverFromGreatest = 0;

  // Distance between the average number and first node from
  // the lowest side
  unsigned int disBettAverFromLowest = 0;

  // Get the sum of all nodes values starting from Head
  CalculateTotalNodesValues(mHeadNode, total);

  average = total / mCount;
  std::cout << "The Total sum of Nodes values is : " << total << "\n";
  std::cout << "The Average number is : " << average << "\n";

  std::cout << "\n\n/---------------------------------------------/ \n";
  std::cout << "Finding the average node from Greatest Side: \n\n";
  unsigned int i = 0;
  while (true)
  {
    average = average + i;

    std::cout << "Node to find is : " << average << "\n";

    tmpGreatestAverageNode = Find(average);
    if (tmpGreatestAverageNode != nullptr)
    {
      break;
    }
    else
    {
      ++disBettAverFromGreatest;
      ++i;
    }
  }

  // Reset Indx
  i = 0;

  std::cout << "\n\n/---------------------------------------------/ \n";
  std::cout << "Finding the average node from Lowest Side: \n\n";
  while (true)
  {
    average = average - i;
    tmpLowestAverageNode = Find(average);
    if (tmpLowestAverageNode != nullptr)
    {
      break;
    }
    else
    {
      ++disBettAverFromLowest;
      ++i;
    }
  }

  if (disBettAverFromGreatest > disBettAverFromLowest)
  {
    std::cout << "The Node selected from Greatest side is : " << tmpLowestAverageNode->n << "\n";
    return tmpGreatestAverageNode;
  }
  else
  {
    std::cout << "The Node selected from Lowest side is : " << tmpLowestAverageNode->n << "\n";
    return tmpLowestAverageNode;
  }
}

void BinaryTree::CalculateTotalNodesValues(Node* node, unsigned int& total)
{
  // Adding node->n values to total
  total += node->n;

  if (node->mLeftDirectionTaken == false)
  {
    if (node->mLower != nullptr)
    {
      CalculateTotalNodesValues(node->mLower, total);
    }
    node->mLeftDirectionTaken = true;
  }

  if (node->mRightDirectionTaken == false)
  {
    if (node->mGreater != nullptr)
    {
      CalculateTotalNodesValues(node->mGreater, total);
    }
    node->mRightDirectionTaken = true;
  }
    node->mLeftDirectionTaken = false;
    node->mRightDirectionTaken = false;
}

Node* BinaryTree::FindNode(Node& node, const int& n)
{
  if (n == node.n)
  {
    return &node;
  }
  else
  {
    if (n < node.n)
    {
      if (node.mLower != nullptr)
      {
        return FindNode(*(node.mLower), n);
      }
    }
    else
    {
      if (node.mGreater != nullptr)
      {
        return FindNode(*(node.mGreater), n);
      }
    }
  }

  return nullptr;
}
// End Vertical Balance Methods

bool BinaryTree::RemoveNode(Node* node, Node& previousNode, const int n)
{
  if (n == node->n)
  {
    // Is in a 80% coded, But we must revise the cases when
    // one of the edges be null in the Node which will going to erase
    if (node->mLower != nullptr && node->n < previousNode.n)
    {
      // Saves the Lower nodes to a TempNode
      Node* tmpLowerChildNode = node->mLower;

      // Set the Lower Temp Part into the Lowest Node of the Greater Child Node part
      // of the Node that I will Erase from the face of the Memory.
      Node* tmpLowestInGreaterChildNode = GetLowestNodeFromThisNode(node->mGreater);

      // Set the Greater Child Node part to the Lower part in the previous Node
      previousNode.mLower = node->mGreater;

      tmpLowestInGreaterChildNode->mLower = tmpLowerChildNode;
    }
    else if (node->mGreater != nullptr && node->n > previousNode.n)
    {
    }

    delete node;
    node = nullptr;
  }
  else if (n < node->n)
  {
    if (node->mLower != nullptr)
    {
      return RemoveNode(node->mLower, *(node), n);
    }
  }
  else
  {
    if (node->mGreater != nullptr)
    {
      return RemoveNode(node->mGreater, *(node), n);
    }
  }

  return false;
}

Node* BinaryTree::GetLowestNodeFromThisNode(Node* node)
{
  if (node->mLower == nullptr)
  {
    return node;
  }
  else
  {
    return GetLowestNodeFromThisNode(node->mLower);
  }
}
