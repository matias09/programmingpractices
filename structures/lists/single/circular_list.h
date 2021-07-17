#ifndef CIRCULAR_SINGLE_LIST_H
#define CIRCULAR_SINGLE_LIST_H

#include <initializer_list>
#include <iostream>

#include <stdlib.h>
#include <stdint.h>

template <typename T>
class CircularSingleList
{
  struct Node
  {
    T     value;
    Node* next;
  };

public:
  explicit CircularSingleList()
    : head(nullptr), length_(0) {}

  explicit CircularSingleList(std::initializer_list<T> elements)
    : head(nullptr), length_(0)
  {
    for (auto const & e : elements)
      Insert(e);
  }

  ~CircularSingleList()
  {
    if (length_ == 0)
      return;

    Node* tail = head;

    while (tail != nullptr && head->next != nullptr) {
      head = head->next;

      free(tail);
      tail = nullptr;
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
      Node* tmp = head;

      while (tmp->next != nullptr)
        tmp = tmp->next;

      Node* new_node = MakeNode();
      new_node->value = e;
      new_node->next = head;

      tmp->next = new_node;
    }

    ++length_;
    return true;
  }

  bool Erase()
  {
    if (length_ == 0)
      return false;

    Node* tmp  = head;
    Node* tail = nullptr;

    while (tmp->next != nullptr) {
      tail = tmp;
      tmp = tmp->next;
    }

    free(tmp);
    tmp = nullptr;

    tail->next = head;

    --length_;
    return true;
  }

  void Print()
  {
    Node* tmp = head;

    while (tmp->next != nullptr) {
      std::cout << tmp->value << ' ';

      tmp = tmp->next;
    }
    std::cout << tmp->value << '\n';
  }

  std::size_t length() const { return length_; }

private:
  Node* MakeNode() const
  {
     Node* new_node = static_cast<Node*>( malloc( sizeof(Node) ) );
     new_node->next = nullptr;
     new_node->value = 0;

     return new_node;
  }

  Node* head;
  std::size_t length_;
};

#endif // CIRCULAR_SINGLE_LIST_H

// Unit Test
