#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>
#include <algorithm>
#include <initializer_list>

class Graph
{
  enum class Color { WHITE = 0, GRAY, BLACK };

public:
  struct Node
  {
    Node(int v = 0)
      : parent(nullptr)
      , color(Color::WHITE)
      , distance(0)
      , value(v) {}

    void AddNeighbors(const std::initializer_list<Node*> & list_nodes)
    {
      for (auto const & e : list_nodes)
        neighbors.emplace_back(e);
    }

    std::vector<Node*> neighbors;
    Node* parent;
    Color color;
    std::size_t distance;
    int value;
  };

   Graph() = default;

   Graph(const std::initializer_list<Node*> & list_nodes)
   {
     for (auto const & e : list_nodes)
       g_.emplace_back(e);
   }

  ~Graph() = default;

  void Create(const std::initializer_list<Node*> & list_nodes)
  {
    for (auto const & e : list_nodes)
      g_.emplace_back(e);
  }

  Node* RunBreathFirstSearch(Node* s, int const needle)
  {
    std::for_each(g_.begin(), g_.end() ,[&] (auto & n) {
      (*n).color = Color::WHITE;
      (*n).distance = 0;
      (*n).parent = nullptr;
    });

    s->distance = 0;
    s->color = Color::GRAY;
    s->parent = nullptr;

    std::queue<Node*> q;
    q.push(s);

    Node* c = nullptr;
    Node* end_path_node = nullptr;

    bool node_found = false;
    while (node_found == false || not q.empty()) {
      c = q.front();
      q.pop();

      auto itB = c->neighbors.begin();
      auto const & itE = c->neighbors.cend();

      for (; itB != itE && node_found == false; ++itB) {
        if ( (*itB)->color == Color::WHITE ) {
          (*itB)->parent = c;
          (*itB)->color = Color::GRAY;
          (*itB)->distance = c->distance + 1;

          q.push((*itB));
        }

        if ((*itB)->value == needle) {
          end_path_node = (*itB);
          node_found = true;
        }
      }
      c->color = Color::BLACK;
    }

    return end_path_node;
  }

  void RunDepthFirstSearch()
  {
    std::for_each(g_.begin(), g_.end() ,[&] (auto & n) {
      (*n).color = Color::WHITE;
      (*n).parent = nullptr;
    });

    std::for_each(g_.begin(), g_.end() ,[&] (auto & n) {
      if ( (*n).color == Color::WHITE )
        DFSVisit( (*n) );
    });
  }

  void DFSVisit(Node & u)
  {
    u.color = Color::GRAY;

    auto itB = u.neighbors.begin();
    auto const & itE = u.neighbors.cend();

    for (; itB != itE; ++itB) {
      if ( (*itB)->color == Color::WHITE ) {
        (*itB)->parent = &u;
        DFSVisit( *(*itB) );
      }
    }
    u.color = Color::BLACK;
  }

private:
  std::vector<Node*> g_;
};

#endif // GRAPH_H
