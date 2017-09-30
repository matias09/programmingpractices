//-------------------------------------------------------------------
// TODO: Improve the Insert Mode to not be so Binary Search Method.
//-------------------------------------------------------------------

#include <iostream>

struct Node
{
  explicit Node(int pdata) { data = pdata; right = nullptr; left = nullptr; }
  ~Node() {};

  int data;
  Node* left;
  Node* right;
};

void Insert(Node& node, const int n)
{
  if (n > node.data)
  {
    if (node.right == nullptr)
    {
      node.right = new Node(n);
    }
    else
    {
      Insert(*node.right, n);
    }
  }
  else
  {
    if (node.left == nullptr)
    {
      node.left = new Node(n);
    }
    else
    {
      Insert(*node.left, n);
    }
  }
}

void Show(Node& node)
{
  if (node.left != nullptr)
  {
    Show(*node.left);
  }

  if (node.right != nullptr)
  {
    Show(*node.right);
  }

  std::cout << node.data << " ";
}

void Release(Node* node)
{
  if (node->left != nullptr)
  {
    Release(node->left);
  }

  if (node->right != nullptr)
  {
    Release(node->right);
  }

  node->data = 0;
  delete node;
  node = nullptr;
}

void FillTree(Node& node)
{
  // level 1
  Insert(node, 225);
  Insert(node, 725);

  // level 2
  Insert(node, 122);
  Insert(node, 370);
  Insert(node, 600);
  Insert(node, 900);

  // level 3
  Insert(node, 90);
  Insert(node, 190);
  Insert(node, 280);
  Insert(node, 425);
  Insert(node, 550);
  Insert(node, 650);
  Insert(node, 800);
  Insert(node, 2000);

  // level 4
  Insert(node, 45);
  Insert(node, 108);
  Insert(node, 130);
  Insert(node, 210);

  node.left->left->data = 99000;
}

bool HasLeftSideInvalidData(Node& node, const int data)
{
  if (node.data >= data)
  {
    return true;
  }
  else
  {
    if (node.left != nullptr)
    {
      if (HasLeftSideInvalidData(*node.left, data))
      {
        return true;
      }
    }

    if (node.right != nullptr)
    {
      if (HasLeftSideInvalidData(*node.right, data))
      {
        return true;
      }
    }
  }

  return false;
}

bool HasRightSideInvalidData(Node& node, const int data)
{
  if (node.data <= data)
  {
    return true;
  }
  else
  {
    if (node.left != nullptr)
    {
      if (HasRightSideInvalidData(*node.left, data))
      {
        return true;
      }
    }

    if (node.right != nullptr)
    {
      if (HasRightSideInvalidData(*node.right, data))
      {
        return true;
      }
    }
  }

  return false;
}

bool checkBST(Node* node)
{
  if (node != nullptr)
  {
    if (node->left != nullptr)
    {
      if (HasLeftSideInvalidData(*node->left, node->data))
      {
        return false;
      }
      else
      {
        if (checkBST(node->left) == false)
        {
          return false;
        }
      }
    }

    if (node->right != nullptr)
    {
      if (HasRightSideInvalidData(*node->right, node->data))
      {
        return false;
      }
      else
      {
        if (checkBST(node->right) == false)
        {
          return false;
        }
      }
    }
  }
  else
  {
    return false;
  }

  return true;
}

int main()
{
  Node* head = new Node(500);
  bool isBinarySearchTree = false;
  std::cout << "\n\n";

  FillTree(*head);
  Show(*head);

  isBinarySearchTree = checkBST(head);

  if (isBinarySearchTree)
  {
    std::cout << "This is a Binary Search Tree . . .\n\n";
  }
  else
  {
    std::cout << "This is .. NOT .. a Binary Search Tree . . .\n\n";
  }

  Release(head);

  return 0;
}
