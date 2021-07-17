#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

#include <initializer_list>
#include <iostream>

#include <stdlib.h>
#include <stdint.h>

template <typename T>
class SingleList
{
  struct Node
  {
    T     value;
    Node* next;
  };

public:
  explicit SingleList()
    : head(nullptr), length_(0) {}

  explicit SingleList(std::initializer_list<T> elements)
    : head(nullptr), length_(0)
  {
    for (auto const & e : elements)
      Insert(e);
  }

  ~SingleList()
  {
    if (length_ == 0)
      return;

    Node* tmp = nullptr;

    while (head != nullptr) {
      tmp = head;
      head = head->next;

      free(tmp);
      tmp = nullptr;
    }
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

      tmp->next = new_node;
    }

    ++length_;
    return true;
  }

  bool Erase()
  {
    if (length_ == 0)
      return false;

    Node* tmp = head;

    while (tmp->next != nullptr)
      tmp = tmp->next;

    free(tmp);
    tmp = nullptr;

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

#endif // SINGLE_LIST_H

// Unit Test
template <typename T>
bool LengthCeroAtEmptyConstruction(T && c)
{
  return c.length() == 0;
}

template <typename T>
bool LengthGreaterThanCeroAtConstructionWithInitializerList(T&& c)
{
  return c.length() > 0;
}

template <typename T>
bool LengthEqualToOneAfterOnePushBack(T&& c)
{
  c.Insert(1);
  return c.length() == 1;
}

template <typename T>
bool LengthBackToCeroAfterOnePushAndOnePop(T&& c)
{
  c.Insert(1);
  c.Erase();
  return c.length() == 0;
}

template <typename T>
bool LengthAfterThreePush(T&& c)
{
  c.Insert(1);
  c.Insert(2);
  c.Insert(3);

  return c.length() == 3;
}

template <typename T>
bool ErrorAfterOnePushAndOnePop(T&& c)
{
  c.Insert(1);
  c.Erase();
  c.Erase();

  return c.length() == false;
}
