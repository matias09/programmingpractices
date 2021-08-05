#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <iostream>
#include <initializer_list>

template <typename T>
class RedBlackTree
{
  enum class Color {BLACK = 0, RED};

  struct Node
  {
    Node(T const & e) : value(e)
                      , parent(nullptr)
                      , left(nullptr)
                      , right(nullptr)
                      , color(Color::BLACK) {}
    T value;
    Node* parent;
    Node* left;
    Node* right;
    Color color;
  };

public:
  RedBlackTree() : root_(nullptr), size_(0) {}

  RedBlackTree(std::initializer_list<T> const elms)
    : root_(nullptr), size_(0)
  {
    for (auto const & e : elms)
      Insert(e);
  }

 ~RedBlackTree()
  {
    if (size_ > 0)
      ReleaseNodes(root_);
  }

  void PrintInOrderTraversal(Node* node) const
  {
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
    new_node->color = Color::RED;

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
    }

    ++size_;
    InsertFixUp(new_node);
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

  Node* GetRoot() const { return root_; }
  std::size_t GetSize() const { return size_; }

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

  void InsertFixUp(Node* z)
  {
    Node* y = nullptr;

    while (z->parent != nullptr && z->parent->color == Color::RED) {
      if (z->parent == z->parent->parent->left) {
        y = z->parent->parent->right;

        if (y->color == Color::RED) {
          z->parent->color = Color::BLACK;
          y->color = Color::BLACK;
          z->parent->parent->color = Color::RED;
          z = z->parent->parent;
        } else if (z->value == z->parent->right->value) {
          z = z->parent;
          LeftRotate(z);
        } else {
          z->parent->color = Color::BLACK;
          z->parent->parent->color = Color::RED;
          RightRotate(z->parent->parent);
        }
      } else {
        y = z->parent->parent->left;

        if (y->color == Color::RED) {
          z->parent->color = Color::BLACK;
          y->color = Color::BLACK;
          z->parent->parent->color = Color::RED;
          z = z->parent->parent;
        } else if (z->value == z->parent->left->value) {
          z = z->parent;
          LeftRotate(z);
        } else {
          z->parent->color = Color::BLACK;
          z->parent->parent->color = Color::RED;
          RightRotate(z->parent->parent);
        }
      }
    }

    root_->color = Color::BLACK;
  }

  Node* root_;
  std::size_t size_;
};

#endif // RED_BLACK_TREE_H
