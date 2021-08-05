#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <initializer_list>

template <typename T>
class AvlTree
{
  struct Node
  {
    Node(T const & e) : value(e)
                      , parent(nullptr)
                      , left(nullptr)
                      , right(nullptr) {}
    T value;
    Node* parent;
    Node* left;
    Node* right;
    int height = 0;
  };

public:
  AvlTree() : root_(nullptr) {}

  AvlTree(std::initializer_list<T> const elms)
    : root_(nullptr)
  {
    for (auto const & e : elms)
      Insert(e);
  }

 ~AvlTree()
  {
    if (GetSize() > 0)
      ReleaseNodes(root_);
  }

  void PrintInOrderTraversal(Node* node) const
  {
    std::cout << node->value << ' ';

    if (node->left != nullptr)
      PrintInOrderTraversal(node->left);

    if (node->right != nullptr)
      PrintInOrderTraversal(node->right);
  }

  void PrintInPreOrderTraversal(Node* node) const
  {
    if (node->left != nullptr)
      PrintInPreOrderTraversal(node->left);

    std::cout << node->value << ' ';

    if (node->right != nullptr)
      PrintInPreOrderTraversal(node->right);
  }

  void Insert(T const & e)
  {
    Node* y = nullptr;
    Node* x = root_;
    Node* new_node = new Node(e);

    while (x != nullptr) {
      y = x;

      if (new_node->value < x->value)
        x = x->left;
      else
        x = x->right;
    }

    new_node->parent = y;

    if (y == nullptr) {
      root_ = new_node;
    } else {
      if (new_node->value < y->value)
        y->left = new_node;
      else
        y->right = new_node;

      UpdateHeight(*new_node);
    }
    ++size_;
  }

  void Transplant(Node* n1, Node* n2)
  {
    if (n1->parent == nullptr)
      root_ = n2;
    else if (n1->value == n1->parent->left->value) {
      n1->parent->left = n2;
      n1->parent->right = n1;
    } else {
      n1->parent->right = n2;
      n1->parent->left = n1;
    }

    if (n2 != nullptr)
      n2->parent = n1->parent;
  }

  void LeftRotate(Node* x)
  {
    Node* y = x->right;
    x->right = y->left;

    if (y->left != nullptr)
      y->left->parent = x;

    y->parent = x->parent;
    if (x->parent == nullptr)
      root_ = y;
    else if (x->value == x->parent->left->value)
      x->parent->left = y;
    else
      x->parent->right = y;

    y->left = x;
    x->parent = y;
  }

  void RightRotate(Node* y)
  {
    Node* x = y->left;
    y->left = x->right;

    if (x->right != nullptr)
      x->right->parent = y;

    x->parent = y->parent;
    if (y->parent == nullptr)
      root_ = x;
    else if (y->value == y->parent->left->value)
      y->parent->left = x;
    else
      y->parent->right = x;

    x->right = y;
    y->parent = x;
  }

  void Erase(Node* node)
  {
    if (node == nullptr)
      return;

    if (node->left == nullptr)
      Transplant(node, node->right);
    else if (node->right == nullptr)
      Transplant(node, node->left);
    else {
      Node* node_min = GetMinimum(node->right);

      if (node_min->parent->value != node->value) {
        Transplant(node_min, node_min->right);
        node_min->right = node->right;
        node_min->right->parent = node_min;
      }

      Transplant(node, node_min);
      node_min->left = node->left;
      node_min->left->parent = node_min;
    }

    delete node;
    node = nullptr;

    --size_;
  }

  Node* GetMinimum(Node* node)
  {
    if (node != nullptr)
      while (node->left != nullptr)
        node = node->left;

    return node;
  }

  std::size_t GetSize() const { return size_; }

  Node* GetRoot() const { return root_; }

private:
  void ReleaseNodes(Node* node)
  {
    if (node->left != nullptr)
      ReleaseNodes(node->left);

    if (node->right != nullptr)
      ReleaseNodes(node->right);

    delete node;
    node = nullptr;
  }

  void UpdateHeight(Node& n)
  {
    int lh = 0, rh = 0;
    Node* tmp = n.parent;

    do {
      if (tmp->left != nullptr)
        lh = tmp->left->height;

      if (tmp->right != nullptr)
        rh = tmp->right->height;

      tmp->height = (lh > rh) ? (lh + 1) : (rh + 1);

      // UpdateBalanceCondition( *tmp, lh, rh );

      tmp = tmp->parent;
    } while (tmp != nullptr);
  }

  void UpdateBalanceCondition(Node& n, int lh, int rh)
  {
    constexpr int unbalanced_height_criteria = 2;
    int cur_height_diff = (lh - rh);

    if (cur_height_diff == unbalanced_height_criteria) {
      if (n.left != nullptr) {
        RightRotate(n);
      } else {
        LeftRotate(n.left);
        RightRotate(n);
      }
    } else if (cur_height_diff == (unbalanced_height_criteria * (-1))) {
      if (n.right->right != nullptr) {
        LeftRotate(n);
      } else {
        RightRotate(n.right);
        LeftRotate(n);
      }
    }
  }

  Node* root_;
  std::size_t size_ = 0;
};

#endif // AVL_TREE_H
