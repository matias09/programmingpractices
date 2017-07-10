#include <iostream>

// Own Classes
#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
  std::cout << " \n Building BinaryTree . . . \n";
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
    std::cout << " -- Nodes Values --\n\t";
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
    SaveNode(mHeadNode, n);
  }

  std::cout << "n = " << n << "\n";
  std::cout << "mLevelInLowestSide = " << mHeadNode->mLevelInLowestSide << "\n";
  std::cout << "mLevelInGreatestSide = " << mHeadNode->mLevelInGreatestSide << "\n";

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

//  std::cout << "mLevelInLowestSide = " << mLevelInLowestSide << "\n";
//  std::cout << "mLevelInGreatestSide = " << mLevelInGreatestSide << "\n";

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

void BinaryTree::SaveNode(Node* node, const int n)
{
  std::cout << "\n\n/---------------------------------------------/ \n";
  std::cout << "[ SaveNode() ] \n";

  if (n > node->n)
  {
    if (node->mGreater == nullptr)
    {
      node->mGreater = new Node(n);
      ++node->mLevelInGreatestSide;
    }
    else
    {
      SaveNode(node->mGreater, n);

      std::cout << "Actual Node : " << node->n << "\n";
      std::cout << "mLevelInGreatestSide = " << node->mLevelInGreatestSide << "\n";

      // Compares both levels in ChildNode to determine which of both
      // we must to use to update the Level counter of the actual Node
      // in the Greatest side
      if (node->mGreater->mLevelInGreatestSide > node->mGreater->mLevelInLowestSide)
      {
        node->mLevelInGreatestSide = node->mGreater->mLevelInGreatestSide + 1;
      }
      else
      {
        node->mLevelInGreatestSide = node->mGreater->mLevelInLowestSide + 1;
      }
    }
  }
  else
  {
    if (node->mLower == nullptr)
    {
      node->mLower = new Node(n);
      ++node->mLevelInLowestSide;
    }
    else
    {
      SaveNode(node->mLower, n);

      // Compares both levels in ChildNode to determine which of both
      // we must to use to update the Level counter of the actual Node
      // in the Lowest side
      if (node->mLower->mLevelInGreatestSide > node->mLower->mLevelInLowestSide)
      {
        node->mLevelInLowestSide = node->mLower->mLevelInGreatestSide + 1;
      }
      else
      {
        node->mLevelInLowestSide = node->mLower->mLevelInLowestSide + 1;
      }
    }
  }

  std::cout << "\n [ End ] \n";
}

// Starts Vertical Balance Methods

void BinaryTree::ProcessBalance(Node* newHeadNode)
{
  if (newHeadNode->n == mHeadNode->n)
  {
    if (newHeadNode->mLevelInGreatestSide > newHeadNode->mLevelInLowestSide)
    {
      newHeadNode = mHeadNode->mGreater;
    }
    else
    {
      newHeadNode = mHeadNode->mLower;
    }
  }

  // Save Head Node in a TmpNode
  Node* tmpPrevHeadNode = mHeadNode;

  // This will be use to save the AvgNode Child nodes
  // in the case that have one
  Node* tmpLowerFromAvgNode = nullptr;
  Node* tmpGreaterFromAvgNode = nullptr;

  // Set if the AvgNode has some child node
  bool hasAvgNodeAnyChild = false;

  // Checking if the Average Node has child nodes created to save then.
  if (newHeadNode->mLower != nullptr)
  {
    tmpLowerFromAvgNode = newHeadNode->mLower;
    hasAvgNodeAnyChild = true;
  }

  if (newHeadNode->mGreater != nullptr)
  {
    tmpGreaterFromAvgNode = newHeadNode->mGreater;
    hasAvgNodeAnyChild = true;
  }

  // Get the parent Node from the newHeadNode
  Node* prevNodeToAvg = FindPrevNode(*(mHeadNode), newHeadNode->n);

  // Technically I have already in this point all the neccesary to play with pointers.
  // As Duke Nuken will say:
  // L E T 'S    R O C K


  // Set Previous HeadNode to the Lower or Higher side of the New HeadNode
  if (newHeadNode->n > tmpPrevHeadNode->n)
  {
    tmpPrevHeadNode->mGreater = nullptr;
  }
  else
  {
    tmpPrevHeadNode->mLower = nullptr;
  }

  if (hasAvgNodeAnyChild)
  {
    if (newHeadNode->n < prevNodeToAvg->n)
    {
      // Cases when the AvgNode be Lower than PrevNodeToAvg
      if (tmpLowerFromAvgNode != nullptr && tmpGreaterFromAvgNode != nullptr)
      {
        // Get the Greater Child Node From Average Node to connect to the
        // Previous Node connected to the Average Node
        Node* tmpGreaterChildAvgNode = GetGreatestNodeFromThisNode(newHeadNode->mGreater);

        // Set the Greatest Child Node from Average Node
        // to the Lowest Node of the Previous Node
        // from the Average Node
        prevNodeToAvg->mLower = tmpGreaterChildAvgNode;

        // Set the Lowest Child Node from Average Node
        // to the last Node of the Greatest Node
        // from the Average Node
        tmpGreaterChildAvgNode->mLower = tmpLowerFromAvgNode;
      }
      else if (tmpLowerFromAvgNode != nullptr)
      {
        prevNodeToAvg->mLower = tmpLowerFromAvgNode;
      }
      else if (tmpGreaterFromAvgNode != nullptr)
      {
        prevNodeToAvg->mLower = tmpGreaterFromAvgNode;
      }
    }
    else
    {
      // Cases when the AvgNode is Greater than PrevNodeToAvg
      if (tmpLowerFromAvgNode != nullptr && tmpGreaterFromAvgNode != nullptr)
      {
        // Get the Lower Child Node From Average Node to connect to the
        // Previous Node connected to the Average Node
        Node* tmpLowerChildAvgNode = GetLowestNodeFromThisNode(newHeadNode->mLower);

        // Set the Lower Child Node from Average Node
        // to the Greatest Node of the Previous Node
        // from the Average Node
        prevNodeToAvg->mGreater = tmpLowerChildAvgNode;

        // Set the Greatest Child Node from Average Node
        // to the last Node of the Lowest Node
        // from the Average Node
        tmpLowerChildAvgNode->mGreater = tmpGreaterFromAvgNode;
      }
      else if (tmpLowerFromAvgNode != nullptr)
      {
        prevNodeToAvg->mGreater = tmpLowerFromAvgNode;
      }
      else if (tmpGreaterFromAvgNode != nullptr)
      {
        prevNodeToAvg->mGreater = tmpGreaterFromAvgNode;
      }
    }
  }
  else
  {
    // Reset the PrevNodeToAvg Node who had the
    // new HeadNode
    if (newHeadNode->n < prevNodeToAvg->n)
    {
      prevNodeToAvg->mLower = nullptr;
    }
    else
    {
      prevNodeToAvg->mGreater = nullptr;
    }
  }

  // Changing HeadNode for newHeadNode
  mHeadNode = newHeadNode;
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
