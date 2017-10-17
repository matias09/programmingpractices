#include <iostream>

// Own Classes
#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
  DEBUG_MSG(" \n Building BinaryTree . . . \n");
  mCount = 0;
  mHeadNode = nullptr;
}

BinaryTree::~BinaryTree()
{
  DEBUG_MSG(" \n Releasing BinaryTree . . . \n");
}

void BinaryTree::ShowElements()
{
  if (mHeadNode != nullptr)
  {
    DEBUG_MSG(" -- Nodes Values --\n\t");
    ShowNode(mHeadNode);
  }
  else
  {
    DEBUG_MSG("Empty Container");
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
  DEBUG_MSG("\n\n/---------------------------------------------/ \n");
  DEBUG_MSG("[ Insert() ] \n");

  // Increase total number count
  ++mCount;

  DEBUG_LOG("mCount = ", mCount);

  if (mHeadNode == nullptr)
  {
    mHeadNode = new Node(n);
  }
  else
  {
    SaveNode(mHeadNode, *mHeadNode, n);
  }

  DEBUG_MSG("\n\n/---------------------------------------------/ \n");
  DEBUG_LOG("- New Node n = ", n);
  DEBUG_LOG("- Head Node mLevelInLowestSide = ", mHeadNode->mLevelInLowestSide);
  DEBUG_LOG("- Head Node mLevelInGreatestSide: ", mHeadNode->mLevelInGreatestSide);
  DEBUG_MSG("\n [ End ] \n");
}

Node* BinaryTree::Find(const int n)
{
  Node* tmpNodeToSet = FindNode(*(mHeadNode), n);
  return tmpNodeToSet;
}

bool BinaryTree::Erase(const int n)
{
  DEBUG_MSG("\n\n/---------------------------------------------/ \n");
  DEBUG_MSG("[ Erase() ] \n");
  DEBUG_LOG("Erasing node : ", n);

  bool wasNodeErased = false;
  wasNodeErased = EraseNode(mHeadNode, *mHeadNode, n);

  if (wasNodeErased)
  {
    --mCount;
  }

  DEBUG_MSG("\n [ End ] \n");
  return wasNodeErased;
}

void BinaryTree::ReleaseTree()
{
  ReleaseNodes(mHeadNode);
}

// ------------------------------------------------------------ //
// --------------------- Private Methods ---------------------- //
// ------------------------------------------------------------ //

void BinaryTree::SaveNode(Node* node, Node& parentNode, const int n)
{
  DEBUG_MSG("\n\n/---------------------------------------------/ \n");
  DEBUG_MSG("[ SaveNode() ] \n");

  if (n > node->n)
  {
    if (node->mGreater == nullptr)
    {
      node->mGreater = new Node(n);
      ++node->mLevelInGreatestSide;
    }
    else
    {
      SaveNode(node->mGreater, *node, n);

      DEBUG_LOG("actual node : ", node->n);
      DEBUG_LOG("mLevelInGreatestSide = ", node->mLevelInGreatestSide);

      // compares both levels in childnode to determine which of both
      // we must to use to update the level counter of the actual node
      // in the greatest side
      if (node->mGreater->mLevelInGreatestSide > node->mGreater->mLevelInLowestSide)
      {
        node->mLevelInGreatestSide = node->mGreater->mLevelInGreatestSide + 1;
      }
      else
      {
        node->mLevelInGreatestSide = node->mGreater->mLevelInLowestSide + 1;
      }

      DEBUG_MSG("\n\n/---------------------------------------------/ \n");
      DEBUG_LOG("- node = ", node->n);
      DEBUG_LOG("- node->mGreater : ", node->mGreater->n);
      DEBUG_LOG("- node->mGreater mLevelInLowestSide = ", node->mGreater->mLevelInLowestSide);
      DEBUG_LOG("- node->mGreater mLevelInGreatestSide: ", node->mGreater->mLevelInGreatestSide);
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
      SaveNode(node->mLower, *node, n);

      // compares both levels in childnode to determine which of both
      // we must to use to update the level counter of the actual node
      // in the lowest side
      if (node->mLower->mLevelInGreatestSide > node->mLower->mLevelInLowestSide)
      {
        node->mLevelInLowestSide = node->mLower->mLevelInGreatestSide + 1;
      }
      else
      {
        node->mLevelInLowestSide = node->mLower->mLevelInLowestSide + 1;
      }

      DEBUG_MSG("\n\n/---------------------------------------------/ \n");
      DEBUG_LOG("- node : ", node->n);
      DEBUG_LOG("- node->mLower : ", node->mLower->n);
      DEBUG_LOG("- node->mLower->mLevelInLowestSide : ", node->mLower->mLevelInLowestSide);
      DEBUG_LOG("- node->mLower->mLevelInGreatestSide : ", node->mLower->mLevelInGreatestSide);
    }
  }

  if ((node->mLevelInGreatestSide - node->mLevelInLowestSide == VERTICAL_CONDITION) || (node->mLevelInLowestSide - node->mLevelInGreatestSide == VERTICAL_CONDITION))
  {
    DEBUG_LOG("Process Balance in Node: ", node->n);
    DEBUG_LOG("Process Balance parent Node: ", parentNode.n);
    ProcessBalance(*node, parentNode);
  }

  DEBUG_MSG("\n [ end ] \n");
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

bool BinaryTree::EraseNode(Node* node, Node& parentNode, const int n)
{
  bool wasNodeDeleted = false;

  if (node->n == n)
  {
    bool eraseFromTheLowetSide = (node->mLevelInLowestSide > node->mLevelInGreatestSide) ? true : false;
    wasNodeDeleted = EraseNodeFlow(node, *node, eraseFromTheLowetSide);

    DEBUG_MSG("\n\n/---------------------------------------------/ \n");
    DEBUG_LOG("- Head Node : ", mHeadNode->n);
    DEBUG_LOG("- Head Node mLevelInLowestSide : ", mHeadNode->mLevelInLowestSide);
    DEBUG_LOG("- Head Node mLevelInGreatestSide: ", mHeadNode->mLevelInGreatestSide);
  }
  else
  {
    if (n > node->n)
    {
      if (node->mGreater->n == n)
      {
        wasNodeDeleted = EraseNodeFlow(node->mGreater, *node, false);
      }
      else
      {
        wasNodeDeleted = EraseNode(node->mGreater, *node, n);
      }

      if (wasNodeDeleted)
      {
        // Update node level counter
        node->mLevelInGreatestSide = (node->mGreater != nullptr) ? GetHigherLevel(*node->mGreater) + 1 : --node->mLevelInGreatestSide;
      }

      DEBUG_MSG("\n\n/---------------------------------------------/ \n");
      DEBUG_LOG("- Head Node : ", node->n);
      DEBUG_LOG("- Head Node mLevelInLowestSide : ", mHeadNode->mLevelInLowestSide);
      DEBUG_LOG("- Head Node mLevelInGreatestSide: ", mHeadNode->mLevelInGreatestSide);
    }
    else
    {
      if (n == node->mLower->n)
      {
        wasNodeDeleted = EraseNodeFlow(node->mLower, *node, true);
      }
      else
      {
        wasNodeDeleted = EraseNode(node->mLower, *node, n);
      }

      if (wasNodeDeleted)
      {
        // Update node level counter
        node->mLevelInLowestSide = (node->mLower != nullptr) ? GetHigherLevel(*node->mLower) + 1 : --node->mLevelInLowestSide;
      }

      DEBUG_MSG("\n\n/---------------------------------------------/ \n");
      DEBUG_LOG("- Head Node : ", node->n);
      DEBUG_LOG("- Head Node mLevelInLowestSide : ", mHeadNode->mLevelInLowestSide);
      DEBUG_LOG("- Head Node mLevelInGreatestSide: ", mHeadNode->mLevelInGreatestSide);
    }
  }

  if ((node->mLevelInGreatestSide - node->mLevelInLowestSide == VERTICAL_CONDITION) || (node->mLevelInLowestSide - node->mLevelInGreatestSide == VERTICAL_CONDITION))
  {
    DEBUG_LOG("Process Balance in Node: ", node->n);
    DEBUG_LOG("Process Balance Parent Node: ", parentNode.n);
    ProcessBalance(*node, parentNode);
  }

  return wasNodeDeleted;
}

bool BinaryTree::EraseNodeFlow(Node* nodeToErase, Node& parentNode, const bool& isTheLowestChild)
{
  // Checks if has childrens
  if (nodeToErase->mLower != nullptr && nodeToErase->mGreater != nullptr)
  {
    Node* selectedSuccessorNode = nullptr;

    const bool getNodeFromLowerSide = (nodeToErase->mLevelInLowestSide > nodeToErase->mLevelInGreatestSide) ? true : false;
    if (getNodeFromLowerSide)
    {
      if (nodeToErase->mLower->mGreater != nullptr)
      {
        // Get the parent of SSN
        // SSN = Selected Successor Node
        Node* parentNodeOfSSN = GetGreatestNodeFromThisNode(nodeToErase->mLower, nodeToErase, true);
        selectedSuccessorNode = new Node(*parentNodeOfSSN->mGreater);

        // Releasing node to avoid Leak Memory
        ReleaseNode(parentNodeOfSSN->mGreater);

        if (selectedSuccessorNode->mLower != nullptr)
        {
          // We are going to join the
          // lower child of SSN to his
          // parent.
          // SSN = selectedSuccessorNode
          parentNodeOfSSN->mGreater = selectedSuccessorNode->mLower;
          parentNodeOfSSN->mLevelInGreatestSide = selectedSuccessorNode->mLevelInLowestSide;
        }
        else
        {
          parentNodeOfSSN->mGreater = nullptr;
          parentNodeOfSSN->mLevelInGreatestSide = 0;
        }

        selectedSuccessorNode->mLower = nodeToErase->mLower;
        selectedSuccessorNode->mLevelInLowestSide = GetHigherLevel(*nodeToErase->mLower) + 1;
      }
      else
      {
        selectedSuccessorNode = new Node(*nodeToErase->mLower);
      }

      selectedSuccessorNode->mGreater = nodeToErase->mGreater;
      selectedSuccessorNode->mLevelInGreatestSide = nodeToErase->mLevelInGreatestSide + 1;
    }
    else
    {
      if (nodeToErase->mGreater->mLower != nullptr)
      {
        // Get the parent of SSN
        // SSN = selectedSuccessorNode
        Node* parentNodeOfSSN = GetLowestNodeFromThisNode(nodeToErase->mGreater, nodeToErase, true);
        selectedSuccessorNode = new Node(*parentNodeOfSSN->mLower);

        // Releasing Node to avoid Leak Memory
        ReleaseNode(parentNodeOfSSN->mLower);

        if (selectedSuccessorNode->mGreater != nullptr)
        {
          // We are going to join the
          // lower child of SSN to his
          // parent.
          // SSN = selectedSuccessorNode
          parentNodeOfSSN->mLower = selectedSuccessorNode->mGreater;
          parentNodeOfSSN->mLevelInLowestSide = selectedSuccessorNode->mLevelInGreatestSide;
        }
        else
        {
          parentNodeOfSSN->mLower = nullptr;
          parentNodeOfSSN->mLevelInLowestSide = 0;
        }

        selectedSuccessorNode->mGreater = nodeToErase->mGreater;
        selectedSuccessorNode->mLevelInGreatestSide = GetHigherLevel(*nodeToErase->mGreater) + 1;
      }
      else
      {
        selectedSuccessorNode = new Node(*nodeToErase->mGreater);
      }

      selectedSuccessorNode->mLower = nodeToErase->mLower;
      selectedSuccessorNode->mLevelInLowestSide = nodeToErase->mLevelInLowestSide + 1;
    }

    // Assign the successor node to his new parent
    // or as a head node
    if (mHeadNode->n != nodeToErase->n)
    {
      if (isTheLowestChild)
      {
        parentNode.mLower = selectedSuccessorNode;
      }
      else
      {
        parentNode.mGreater = selectedSuccessorNode;
      }
    }
    else
    {
      // Set as a head node
      mHeadNode = selectedSuccessorNode;
    }
  }
  else if (nodeToErase->mLower != nullptr)
  {
    // Assign the successor node to his new parent
    // or as a head node
    if (mHeadNode->n != nodeToErase->n)
    {
      if (isTheLowestChild)
      {
        parentNode.mLower = nodeToErase->mLower;
      }
      else
      {
        parentNode.mGreater = nodeToErase->mLower;
      }
    }
    else
    {
      mHeadNode = nodeToErase->mLower;
    }
  }
  else if (nodeToErase->mGreater != nullptr)
  {
    // Assign the successor node to his new parent
    // or as a head node
    if (mHeadNode->n != nodeToErase->n)
    {
      if (isTheLowestChild)
      {
        parentNode.mLower = nodeToErase->mGreater;
      }
      else
      {
        parentNode.mGreater = nodeToErase->mGreater;
      }
    }
    else
    {
      mHeadNode = nodeToErase->mGreater;
    }
  }
  else
  {
    if (isTheLowestChild)
    {
      parentNode.mLower = nullptr;
    }
    else
    {
      parentNode.mGreater = nullptr;
    }
  }

  // Erasing Node from the Tree
  ReleaseNode(nodeToErase);

  return true;
}

void BinaryTree::ProcessBalance(Node& node, Node& parentNode)
{
    Node* selectedSuccessorNode = nullptr;
    bool nodeGrabbedFromAnInternalTree = false;

    const bool getNodeFromLowerSide = (node.mLevelInLowestSide > node.mLevelInGreatestSide) ? true : false;
    if (getNodeFromLowerSide)
    {
      if (node.mLower->mGreater != nullptr)
      {
        nodeGrabbedFromAnInternalTree = true;

        // Get the parent of SSN
        // SSN = Selected Successor Node
        Node* parentNodeOfSSN = GetGreatestNodeFromThisNode(node.mLower, &node, true);
        selectedSuccessorNode = new Node(*parentNodeOfSSN->mGreater);

        // Releasing node to avoid Leak Memory
        ReleaseNode(parentNodeOfSSN->mGreater);

        if (selectedSuccessorNode->mLower != nullptr)
        {
          // We are going to join the
          // lower child of SSN to his
          // parent.
          // SSN = selectedSuccessorNode
          parentNodeOfSSN->mGreater = selectedSuccessorNode->mLower;
          parentNodeOfSSN->mLevelInGreatestSide = selectedSuccessorNode->mLevelInLowestSide;
        }
        else
        {
          parentNodeOfSSN->mGreater = nullptr;
          parentNodeOfSSN->mLevelInGreatestSide = 0;
        }

        // Assigns the reference to not lose
        // the inner tree
        selectedSuccessorNode->mLower = node.mLower;
        selectedSuccessorNode->mLevelInLowestSide = GetHigherLevel(*node.mLower) + 1;
      }
      else
      {
        selectedSuccessorNode = new Node(*node.mLower);
        if (node.mLower->mLower != nullptr)
        {
          selectedSuccessorNode->mLower = node.mLower->mLower;
          selectedSuccessorNode->mLevelInLowestSide = selectedSuccessorNode->mLower->mLevelInLowestSide + 1;
        }
      }

      // This avoid to have two reference
      // to the same node
      node.mLower = nullptr;
      node.mLevelInLowestSide = 0;

      // Set the unbalance head node as a child
      // of the new head node of this tree
      selectedSuccessorNode->mGreater = &node;

      // Set the greater level amount of the previous head node
      // plus one level for the previous head node
      selectedSuccessorNode->mLevelInGreatestSide = node.mLevelInGreatestSide + 1;
    }
    else
    {
      if (node.mGreater->mLower != nullptr)
      {
        nodeGrabbedFromAnInternalTree = true;

        // Get the parent of SSN
        // SSN = selectedSuccessorNode
        Node* parentNodeOfSSN = GetLowestNodeFromThisNode(node.mGreater, &node, true);
        selectedSuccessorNode = new Node(*parentNodeOfSSN->mLower);

        // Releasing Node to avoid Leak Memory
        ReleaseNode(parentNodeOfSSN->mLower);

        if (selectedSuccessorNode->mGreater != nullptr)
        {
          // We are going to join the
          // lower child of SSN to his
          // parent.
          // SSN = selectedSuccessorNode
          parentNodeOfSSN->mLower = selectedSuccessorNode->mGreater;
          parentNodeOfSSN->mLevelInLowestSide = selectedSuccessorNode->mLevelInGreatestSide;
        }
        else
        {
          parentNodeOfSSN->mLower = nullptr;
          parentNodeOfSSN->mLevelInLowestSide = 0;
        }

        // Assigns the reference to not lose
        // the inner tree
        selectedSuccessorNode->mGreater = node.mGreater;
        selectedSuccessorNode->mLevelInGreatestSide = GetHigherLevel(*node.mGreater) + 1;
      }
      else
      {
        selectedSuccessorNode = new Node(*node.mGreater);
        if (node.mGreater->mGreater != nullptr)
        {
          selectedSuccessorNode->mGreater = node.mGreater->mGreater;
          selectedSuccessorNode->mLevelInGreatestSide = selectedSuccessorNode->mGreater->mLevelInGreatestSide + 1;
        }
      }

      // This avoid to have two reference
      // to the same node
      node.mGreater = nullptr;
      node.mLevelInGreatestSide = 0;

      // Set the unbalance head node as a child
      // of the new head node of this tree
      selectedSuccessorNode->mLower = &node;

      // Set the lower level amount of the previous head node
      // plus one level for the previous head node
      selectedSuccessorNode->mLevelInLowestSide = node.mLevelInLowestSide + 1;
    }

    // Assign the successor node to his new parent
    // or as a head node
    if (mHeadNode->n != node.n)
    {
      if (parentNode.n > node.n)
      {
        parentNode.mLower = selectedSuccessorNode;
        parentNode.mLevelInLowestSide = GetHigherLevel(*parentNode.mLower) + 1;
      }
      else
      {
        parentNode.mGreater = selectedSuccessorNode;
        parentNode.mLevelInGreatestSide = GetHigherLevel(*parentNode.mGreater) + 1;
      }

      if (nodeGrabbedFromAnInternalTree)
      {
        if (getNodeFromLowerSide)
        {
          CheckUnbalanced(*selectedSuccessorNode->mLower, parentNode);
        }
        else
        {
          CheckUnbalanced(*selectedSuccessorNode->mGreater, parentNode);
        }
      }
    }
    else
    {
      // Set as a head node
      mHeadNode = selectedSuccessorNode;

      if (nodeGrabbedFromAnInternalTree)
      {
        if (getNodeFromLowerSide)
        {
          CheckUnbalanced(*mHeadNode->mLower, *mHeadNode);
          mHeadNode->mLevelInLowestSide = GetHigherLevel(*mHeadNode->mLower) + 1;
        }
        else
        {
          CheckUnbalanced(*mHeadNode->mGreater, *mHeadNode);
          mHeadNode->mLevelInGreatestSide = GetHigherLevel(*mHeadNode->mGreater) + 1;
        }
      }
    }
}

Node* BinaryTree::GetLowestNodeFromThisNode(Node* node, Node* parentNode, const bool& returnParentNode)
{
  if (node->mLower == nullptr)
  {
    if (returnParentNode)
    {
      return parentNode;
    }
    else
    {
      return node;
    }
  }
  else
  {
    return GetLowestNodeFromThisNode(node->mLower, node, returnParentNode);
  }
}

Node* BinaryTree::GetGreatestNodeFromThisNode(Node* node, Node* parentNode, const bool& returnParentNode)
{
  if (node->mGreater == nullptr)
  {
    if (returnParentNode)
    {
      return parentNode;
    }
    else
    {
      return node;
    }
  }
  else
  {
    return GetGreatestNodeFromThisNode(node->mGreater, node, returnParentNode);
  }
}

void BinaryTree::ReleaseNodes(Node* node)
{
  if (node->mLeftDirectionTaken == false)
  {
    if (node->mLower != nullptr)
    {
      ReleaseNodes(node->mLower);
    }
    node->mLeftDirectionTaken = true;
  }

  if (node->mRightDirectionTaken == false)
  {
    if (node->mGreater != nullptr)
    {
      ReleaseNodes(node->mGreater);
    }
    node->mRightDirectionTaken = true;
  }

  ReleaseNode(node);
}

void BinaryTree::CheckUnbalanced(Node& node, Node& parentNode)
{
  if (node.mLower != nullptr)
  {
    if (node.mLower->mLevelInLowestSide > 1 || node.mLower->mLevelInGreatestSide > 1)
    {
      CheckUnbalanced(*node.mLower, node);
    }
  }

  if (node.mGreater != nullptr)
  {
    if (node.mGreater->mLevelInLowestSide > 1 || node.mGreater->mLevelInGreatestSide > 1)
    {
      CheckUnbalanced(*node.mGreater, node);
    }
  }

  if ((node.mLevelInGreatestSide - node.mLevelInLowestSide == VERTICAL_CONDITION) || (node.mLevelInLowestSide - node.mLevelInGreatestSide == VERTICAL_CONDITION))
  {
    DEBUG_LOG("Process Balance in Node: ", node.n);
    DEBUG_LOG("Process Balance parent Node: ", parentNode.n);
    ProcessBalance(node, parentNode);
  }
}

unsigned int BinaryTree::GetHigherLevel(const Node& node) const
{
  unsigned int higherLevelValue = 0;

  if (node.mLevelInLowestSide > node.mLevelInGreatestSide)
  {
    higherLevelValue = node.mLevelInLowestSide;
  }
  else
  {
    higherLevelValue = node.mLevelInGreatestSide;
  }

  return higherLevelValue;
}

void BinaryTree::ReleaseNode(Node* node)
{
    delete node;
    node->n = 0;
    node->mLeftDirectionTaken = false;
    node->mRightDirectionTaken = false;
    node->mLevelInLowestSide = 0;
    node->mLevelInGreatestSide = 0;
    node->mLower = nullptr;
    node->mGreater = nullptr;
    node = nullptr;
}