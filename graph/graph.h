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
  struct Edge;

  struct Node
  {
    Node(int v = 0) : value(v) {}

    void AddNeighbors(Node* n, std::size_t w = -1)
    {
      neighbors.emplace_back(new Edge(n, w));
    }

    void AddNeighbors(const std::initializer_list<Node*> & list_nodes)
    {
      for (auto const & n : list_nodes)
        AddNeighbors(n);
    }

    std::vector<Edge*> neighbors;
    Node* parent = nullptr;
    Color color = Color::WHITE;
    std::size_t distance = 0;
    int value;
  };

  struct Edge
  {
    Edge(Node* n, std::size_t w = -1)
      : n(n), w(w) {}

    Node* n;
    std::size_t w;
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

  Node* RunBreadthFirstSearch(Node* s, int const needle)
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
        Node* cur_node = (*itB)->n;

        if ( cur_node->color == Color::WHITE ) {
          cur_node->parent = c;
          cur_node->color = Color::GRAY;
          cur_node->distance = c->distance + 1;

          q.push(cur_node);
        }

        if (cur_node->value == needle) {
          end_path_node = cur_node;
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
      Node* cur_node = (*itB)->n;

      if ( cur_node->color == Color::WHITE ) {
        cur_node->parent = &u;
        DFSVisit( *cur_node );
      }
    }
    u.color = Color::BLACK;
  }

private:
  std::vector<Node*> g_;
};

#endif // GRAPH_H
