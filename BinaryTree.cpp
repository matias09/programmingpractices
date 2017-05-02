#include <iostream>
#include <stdexcept>

// Own Classes
#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
  std::cout << " \n Building BinaryTree . . . \n";
  mCountGreatestNumbers = 0;
  mCountLowestNumbers = 0;
  mHighestNodeValue = 0;
  mLowestNodeValue = 0;
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
    // Increase total number count
    ++mCount;

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

      // Evaluate if the Tree is balanced
      if ((mCountGreatestNumbers - mCountLowestNumbers) == 2 || (mCountLowestNumbers - mCountGreatestNumbers) == 2)
      {
        std::cout << " --- Calling to ProcessVerticalBalance() --- ";

        // This Doesn't work yet. But Will be fix during the week
        ProcessVerticalBalance(); // Working Progress . . .
      }
      else
      {
        std::cout << "If a don't mistake in the previous check, so the tree is balanced . . .\n\n";
      }
    }

    UpdateHighestLowestNode(n);
  }
  catch(std::runtime_error& e)
  {
    // Decrease total number count because an error was triggered
    --mCount;

    std::cout << "Exception Catched . . . \n";
    std::cout << "Exception message  \n \t --- " << e.what() << " ---";
    std::cout << "Trying to save a Node \n";
  }
}

Node* BinaryTree::Find(const int n)
{
  Node* tmpNodeToSet = FindNode(*(mHeadNode), n);
  return tmpNodeToSet;
}

bool BinaryTree::Erase(const int n)
{
  return EraseNode(mHeadNode, *(mHeadNode), n);
}

// ------------------------------------------------------------ //
// --------------------- Private Methods ---------------------- //
// ------------------------------------------------------------ //

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
  // Getting the average between this two nodes
  // we will get the new head Node and from he
  // the Tree will be reconstruct
  Node* tmpGreatestAverageNode = nullptr;
  Node* tmpLowestAverageNode = nullptr;

  // The numbers could be all negatives. You don't have to put "unsigned"
  int total = 0;
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
  std::cout << "Finding the average node counting from the average to Highest Node: \n\n";
  while (average < mHighestNodeValue)
  {
    ++average;
    tmpGreatestAverageNode = FindNode(*mHeadNode, average);
    if (tmpGreatestAverageNode != nullptr)
    {
      std::cout << "Node finded.  Is : " << average << "\n \n";
      break;
    }
    else
    {
      ++disBettAverFromGreatest;
    }
  }

  // Reset Average
  average = total / mCount;

  std::cout << "\n\n/---------------------------------------------/ \n";
  std::cout << "Finding the average node counting from the average to Lowest Node: \n\n";
  while (average > mLowestNodeValue)
  {
    --average;
    tmpLowestAverageNode = FindNode(*mHeadNode, average);
    if (tmpLowestAverageNode != nullptr)
    {
      break;
    }
    else
    {
      ++disBettAverFromLowest;
    }
  }

  if (disBettAverFromGreatest > disBettAverFromLowest)
  {
    std::cout << "The Node selected from counting through the average to Lowest Node is : " << tmpLowestAverageNode->n << "\n";
    return tmpLowestAverageNode;
  }
  else
  {
    std::cout << "The Node selected from counting through the average to Highest Node is : " << tmpGreatestAverageNode->n << "\n";
    return tmpGreatestAverageNode;
  }
}

void BinaryTree::CalculateTotalNodesValues(Node* node, int& total)
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

// ------- S T A R T
  // ------ Erase Node()  ---------------------------
bool BinaryTree::EraseNode(Node* node, Node& previousNode, const int n)
{
  static bool theNodeWasDeleted = false;

  // --------------------- R E V I S E ---------------------------
  // TODO: For some reason in Visual Studio compiler, when we erase the last node.
  // Set his value as a long negative value.
  // --------------------- R E V I S E ---------------------------

  if (n == mHeadNode->n)
  {
    // Declares a tmpNode to save the new Head Node
    Node* tmpNewHeadNode = nullptr;

    if (node->mLower != nullptr && node->mGreater != nullptr)
    {
      // Saves the Lower nodes to a TmpNode
      tmpNewHeadNode = node->mLower;

      // Set the Greater Temp Part into the Greatest Node of the Lower Child Node part
      // of the Node that I will Erase from the face of the Memory.
      Node* tmpGreatestInLowestChildNode = GetGreatestNodeFromThisNode(node->mLower);

      // Set the Greatest Node from the previous Node to the Greatest Node
      // from the New Head Node
      tmpGreatestInLowestChildNode->mGreater = mHeadNode->mGreater;
    }
    else if (node->mLower != nullptr)
    {
      // Saves the Lower nodes to a TmpNode
      tmpNewHeadNode = node->mLower;
    }
    else if (node->mGreater != nullptr)
    {
      // Saves the Greater nodes to a TempNode
      tmpNewHeadNode = node->mGreater;
    }

    // Set new Head Node
    mHeadNode = tmpNewHeadNode;

    // Set that we could delete the node
    theNodeWasDeleted = true;

    // Releasing Node from Memory
    ReleaseNode(node);
  }
  else if (n == node->n)
  {
    if (node->n < previousNode.n)
    {
      if (node->mLower != nullptr && node->mGreater != nullptr)
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
      else if (node->mLower != nullptr)
      {
        previousNode.mLower = node->mLower;
      }
      else if (node->mGreater != nullptr)
      {
        previousNode.mLower = node->mGreater;
      }
    }
    else if (node->mLower != nullptr && node->mGreater != nullptr)
    {
      // Saves the Greater nodes to a TempNode
      Node* tmpGreaterChildNode = node->mGreater;

      // Set the Greater Temp Part into the Greatest Node of the Lower Child Node part
      // of the Node that I will Erase from the face of the Memory.
      Node* tmpGreatestInLowestChildNode = GetGreatestNodeFromThisNode(node->mLower);

      // Set the Greater Child Node part to the Lower part in the previous Node
      previousNode.mGreater = node->mLower;

      tmpGreatestInLowestChildNode->mGreater = tmpGreaterChildNode;
    }
    else if (node->mLower != nullptr)
    {
      previousNode.mGreater = node->mLower;
    }
    else if (node->mGreater != nullptr)
    {
      previousNode.mGreater = node->mGreater;
    }

    // Set that we could delete the node
    theNodeWasDeleted = true;

    // Releasing Node from Memory
    ReleaseNode(node);
  }
  else if (n < node->n)
  {
    if (node->mLower != nullptr)
    {
      return EraseNode(node->mLower, *(node), n);
    }
  }
  else
  {
    if (node->mGreater != nullptr)
    {
      return EraseNode(node->mGreater, *(node), n);
    }
  }

  return theNodeWasDeleted;
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

Node* BinaryTree::GetGreatestNodeFromThisNode(Node* node)
{
  if (node->mGreater == nullptr)
  {
    return node;
  }
  else
  {
    return GetGreatestNodeFromThisNode(node->mGreater);
  }
}

  // ------ Erase Node()  ---------------------------
// -- E N D S

void BinaryTree::UpdateHighestLowestNode(const int n)
{
  if (n > mHighestNodeValue)
  {
    mHighestNodeValue = n;
  }
  else if (n < mLowestNodeValue)
  {
    mLowestNodeValue = n;
  }
}

inline void BinaryTree::ReleaseNode(Node* node)
{
    delete node;
    node->mLower = nullptr;
    node->mGreater = nullptr;
    node = nullptr;

    --mCount;
}
