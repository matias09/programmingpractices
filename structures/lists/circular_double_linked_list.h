#ifndef CIRCULAR_DOUBLE_LIST_H
#define CIRCULAR_DOUBLE_LIST_H

#include <initializer_list>
#include <iostream>

#include <stdlib.h>
#include <stdint.h>

template <typename T>
class CircularDoubleList
{
  struct Node
  {
    T     value;
    Node* next;
    Node* prev;
  };

public:
  explicit CircularDoubleList()
    : head(nullptr), length_(0) {}

  explicit CircularDoubleList(std::initializer_list<T> elements)
    : head(nullptr), length_(0)
  {
    for (auto const & e : elements)
      Insert(e);
  }

  ~CircularDoubleList()
  {
    if (length_ == 0)
      return;

    Node* tail = head;

    while (tail != nullptr && head->next != nullptr) {
      head = head->next;

      free(tail);
      tail = head;
    }

    free(head);
    head = nullptr;
  }

  bool Insert(T const & e)
  {
    if (length_ == 0) {
      head = MakeNode();
      head->value = e;
    } else {
      Node* new_node = MakeNode();
      new_node->value = e;

      new_node->next = head;
      head->prev = new_node;

      head = new_node;
    }

    ++length_;
    return true;
  }

  bool Insert(T const & e, std::size_t const idx)
  {
    if (idx < 0 || idx > length_)
      return false;

    Node* new_node = MakeNode();
    new_node->value = e;

    if (idx == 0) {
      new_node->next = head;
      head->prev = new_node;
      head = new_node;
    } else {
      Node* tmp = head;
      Node* tail = head;

      for (size_t i = 0; i < idx; ++i) {
        tail = tmp;
        tmp = tmp->next;
      }

      new_node->next = tmp;
      new_node->prev = tail;

      tmp->prev = new_node;
      tail->next = new_node;
    }

    ++length_;
    return true;
  }

  bool Erase()
  {
    if (length_ == 0)
      return false;

    Node* tmp = head;
    head = head->next;

    free(tmp);
    tmp = nullptr;

    --length_;
    return true;
  }

  bool Erase(std::size_t const idx)
  {
    if (length_ == 0 || idx < 0 || idx > length_)
      return false;

    Node* tmp = head;

    if (idx == 0) {
      head = head->next;
    } else {
      Node* tail = head;

      for (size_t i = 0; i < idx; ++i) {
        tail = tmp;
        tmp = tmp->next;
      }

      tail->next = tmp->next;

      if (tmp->next != nullptr)
        tmp->next->prev = tail;
    }

    free(tmp);
    tmp = nullptr;

    --length_;
    return true;
  }

  Node* At(size_t const idx) const
  {
    if (idx < 0 || idx >= length_)
      return nullptr;

    Node* tmp = head;

    for (size_t i = 0; i < idx; ++i)
      tmp = tmp->next;

    return tmp;
  }

  void Print()
  {
    Node* tmp = head;

    for (size_t i = 1; i < length_; ++i, tmp = tmp->next)
      std::cout << tmp->value << ' ';
  }

  std::size_t length() const { return length_; }

private:
  Node* MakeNode() const
  {
     Node* new_node = static_cast<Node*>( malloc( sizeof(Node) ) );
     new_node->next = nullptr;
     new_node->prev = nullptr;
     new_node->value = 0;

     return new_node;
  }

  Node* head;
  std::size_t length_;
};

#endif // CIRCULAR_DOUBLE_LIST_H
