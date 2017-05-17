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
  std::cout << "\n\n/---------------------------------------------/ \n";
  std::cout << "[ Insert() ] \n";

  // Increase total number count
  ++mCount;

  std::cout << "mCount = " << mCount << "\n";

  if (mHeadNode == nullptr)
  {
    mHeadNode = new Node(n);
  }
  else
  {
    unsigned int levelCounter = START_POINT_VERTICAL_LEVEL;
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

    if (mCount > NODE_AMOUNT_TO_CHECK_BALANCE)
    {
      WasBalanceProcessMade();
    }

  }

  UpdateHighestLowestNode(n);

  std::cout << "n = " << n << "\n";
  std::cout << "mCountLowestNumbers = " << mCountLowestNumbers << "\n";
  std::cout << "mCountGreatestNumbers = " << mCountGreatestNumbers << "\n";

  std::cout << "\n [ End ] \n";
}

Node* BinaryTree::Find(const int n)
{
  Node* tmpNodeToSet = FindNode(*(mHeadNode), n);
  return tmpNodeToSet;
}

bool BinaryTree::Erase(const int n)
{
  std::cout << "\n\n/---------------------------------------------/ \n";
  std::cout << "[ Erase() ] \n";

  bool wasNodeErased = false;
  wasNodeErased = EraseNode(mHeadNode, *(mHeadNode), n);

  if (wasNodeErased)
  {
    if (n < mHeadNode->n)
    {
      --mCountLowestNumbers;
    }
    else
    {
      --mCountGreatestNumbers;
    }

    if (mCount > NODE_AMOUNT_TO_CHECK_BALANCE)
    {
      WasBalanceProcessMade();
    }
  }

  std::cout << "mCountLowestNumbers = " << mCountLowestNumbers << "\n";
  std::cout << "mCountGreatestNumbers = " << mCountGreatestNumbers << "\n";

  std::cout << "\n [ End ] \n";
  return wasNodeErased;
}

void BinaryTree::ReleaseTree()
{
  ReleaseNodesRecursively(mHeadNode);
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

void BinaryTree::ProcessVerticalBalance()
{
  Node* tmpAverageNode = GetAverageNode();

  std::cout << "\n\n/---------------------------------------------/ \n";
  std::cout << "The Average selected Node is : " << tmpAverageNode->n << "\n";

  MakeVerticalChanges(tmpAverageNode);
}

void BinaryTree::MakeVerticalChanges(Node* avgNode)
{
  // Save Head Node in a TmpNode
  Node* tmpPrevHeadNode = mHeadNode;

  // This will be use to save the Child nodes
  // AvgNode in the case that have one
  Node* tmpLowestFromAvgNode = nullptr;
  Node* tmpGreatestFromAvgNode = nullptr;

  // Set if the AvgNode has some child node
  bool hasAvgNodeAnyChild = false;

  // Checking if the Average Node has child nodes created to save then.
  if (avgNode->mLower != nullptr)
  {
    tmpLowestFromAvgNode = avgNode->mLower;
    hasAvgNodeAnyChild = true;
  }

  if (avgNode->mGreater != nullptr)
  {
    // Save the Greatest Node from the Average Node
    tmpGreatestFromAvgNode = avgNode->mGreater;
    hasAvgNodeAnyChild = true;
  }

  // Get the parent Node from the avgNode
  Node* prevNodeToAvg = FindPrevNode(*(mHeadNode), avgNode->n);

  // Technically I have already in this point all the neccesary to play with pointers.
  // As Duke Nuken will say:
  // L E T 'S    R O C K

  // Changing HeadNode for AvgNode
  mHeadNode = avgNode;

  // Set Previous HeadNode to the Lower or Higher side of the New HeadNode
  if (mHeadNode->n > tmpPrevHeadNode->n)
  {
    tmpPrevHeadNode->mGreater = nullptr;
    mHeadNode->mLower = tmpPrevHeadNode;
    mHeadNode->mGreater = prevNodeToAvg;
  }
  else
  {
    tmpPrevHeadNode->mLower = nullptr;
    mHeadNode->mGreater = tmpPrevHeadNode;
    mHeadNode->mLower = prevNodeToAvg;
  }

  if (hasAvgNodeAnyChild)
  {
    if (avgNode->n < prevNodeToAvg->n)
    {
      // Cases when the AvgNode be Lower than PrevNodeToAvg
      if (tmpLowestFromAvgNode != nullptr && tmpGreatestFromAvgNode != nullptr)
      {
        // Get the Greater Child Node From Average Node to connect to the
        // Previous Node connected to the Average Node
        Node* tmpGreaterChildAvgNode = GetGreatestNodeFromThisNode(avgNode->mGreater);

        // Set the Greatest Child Node from Average Node
        // to the Lowest Node of the Previous Node
        // from the Average Node
        prevNodeToAvg->mLower = tmpGreaterChildAvgNode;

        // Set the Lowest Child Node from Average Node
        // to the last Node of the Greatest Node
        // from the Average Node
        tmpGreaterChildAvgNode->mLower = tmpLowestFromAvgNode;
      }
      else if (tmpLowestFromAvgNode != nullptr)
      {
        prevNodeToAvg->mLower = tmpLowestFromAvgNode;
      }
      else if (tmpGreatestFromAvgNode != nullptr)
      {
        prevNodeToAvg->mLower = tmpGreatestFromAvgNode;
      }
    }
    else
    {
      // Cases when the AvgNode is Greater than PrevNodeToAvg
      if (tmpLowestFromAvgNode != nullptr && tmpGreatestFromAvgNode != nullptr)
      {
        // Get the Lower Child Node From Average Node to connect to the
        // Previous Node connected to the Average Node
        Node* tmpLowerChildAvgNode = GetLowestNodeFromThisNode(avgNode->mLower);

        // Set the Lower Child Node from Average Node
        // to the Greatest Node of the Previous Node
        // from the Average Node
        prevNodeToAvg->mGreater = tmpLowerChildAvgNode;

        // Set the Greatest Child Node from Average Node
        // to the last Node of the Lowest Node
        // from the Average Node
        tmpLowerChildAvgNode->mGreater = tmpGreatestFromAvgNode;
      }
      else if (tmpLowestFromAvgNode != nullptr)
      {
        prevNodeToAvg->mGreater = tmpLowestFromAvgNode;
      }
      else if (tmpGreatestFromAvgNode != nullptr)
      {
        prevNodeToAvg->mGreater = tmpGreatestFromAvgNode;
      }
    }
  }
  else
  {
    // Reset the PrevNodeToAvg Node who had the
    // new HeadNode
    if (avgNode->n < prevNodeToAvg->n)
    {
      prevNodeToAvg->mLower = nullptr;
    }
    else
    {
      prevNodeToAvg->mGreater = nullptr;
    }
  }
}

Node* BinaryTree::GetAverageNode()
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

  // THIS HAS TO BE A TREE PROPERTY mTotal = NODE_1 + NODE_2 + NODE_N
  // Get the sum of all nodes values starting from Head
  CalculateTotalNodesValues(mHeadNode, total);

  average = total / static_cast<int>(mCount); // TODO: Search a better way. Not use cast
  std::cout << "\n\n The Total sum of Nodes values is : " << total << "\n";
  std::cout << "The Average number is : " << average << "\n";

  //std::cout << "\n\n/---------------------------------------------/ \n";
  //std::cout << "Finding the average node counting from the average to Highest Node: \n\n";
  while (average < mHighestNodeValue)
  {
    ++average;
    tmpGreatestAverageNode = FindNode(*mHeadNode, average);
    if (tmpGreatestAverageNode != nullptr)
    {
      break;
    }
    else
    {
      ++disBettAverFromGreatest;
    }
  }

  // Reset Average
  average = total / static_cast<int>(mCount); // TODO: Search a better way. Not use cast

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
    return tmpLowestAverageNode;
  }
  else
  {
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

Node* BinaryTree::FindPrevNode(Node& node, const int& n)
{
  if (n < node.n)
  {
    if (node.mLower->n == n)
    {
      return &node;
    }
    else
    {
      return FindPrevNode(*(node.mLower), n);
    }
  }
  else
  {
    if (node.mGreater->n == n)
    {
      return &node;
    }
    else
    {
      return FindPrevNode(*(node.mGreater), n);
    }
  }
}

// Vertical Balance Methods
// -- E N D S

// ------- S T A R T
  // ------ Erase Node()  ---------------------------
bool BinaryTree::EraseNode(Node* node, Node& previousNode, const int n)
{
  static bool theNodeWasDeleted = false;

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
      else
      {
        previousNode.mLower = nullptr;
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
    else
    {
      previousNode.mGreater = nullptr;
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

void BinaryTree::ReleaseNodesRecursively(Node* node)
{
  if (node->mLeftDirectionTaken == false)
  {
    if (node->mLower != nullptr)
    {
      ReleaseNodesRecursively(node->mLower);
    }
    node->mLeftDirectionTaken = true;
  }

  if (node->mRightDirectionTaken == false)
  {
    if (node->mGreater != nullptr)
    {
      ReleaseNodesRecursively(node->mGreater);
    }
    node->mRightDirectionTaken = true;
  }

  ReleaseNode(node);
}

inline void BinaryTree::ReleaseNode(Node* node)
{
    delete node;
    node->mLower = nullptr;
    node->mGreater = nullptr;
    node = nullptr;

    --mCount;
}

bool BinaryTree::WasBalanceProcessMade()
{
  std::cout << "\n\n/---------------------------------------------/ \n";
  std::cout << "[ WasBalanceProcessMade() ] \n";

  bool wasBalanceProcessMade = false;


  std::cout << "(mCountGreatestNumbers - mCountLowestNumbers) = " << (mCountGreatestNumbers - mCountLowestNumbers) << "\n";

  std::cout << "(mCountLowestNumbers - mCountGreatestNumbers) = " << (mCountLowestNumbers - mCountGreatestNumbers) << "\n";

  // Evaluate if the tree got more than two vertical levels
  // of difference
  if ((mCountGreatestNumbers - mCountLowestNumbers) >= VERTICAL_CONDITION || (mCountLowestNumbers - mCountGreatestNumbers) >= VERTICAL_CONDITION)
  {
    std::cout << "Running Balance Process . . .\n";
    ProcessVerticalBalance();
    wasBalanceProcessMade = true;
  }
  else
  {
    std::cout << "The tree remains balanced . . .\n";
  }

  std::cout << "\n [ End ] \n";
  return wasBalanceProcessMade;
}
