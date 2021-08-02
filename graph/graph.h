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

    void AddNeighbors(const std::initializer_list<Node*> & list_nodes)
    {
      for (auto const & n : list_nodes)
        neighbors.emplace_back(n);
    }

    std::vector<Node*> neighbors;
    Node* parent = nullptr;
    Color color = Color::WHITE;
    int distance = 0;
    int value;
  };

  struct Edge
  {
    Edge(Node* u, Node* v, int w = -1)
      : u(u), v(v), w(w) {}

    Node* u;
    Node* v;
    int w;
  };

   Graph() = default;

   Graph(const std::initializer_list<Node*> & list_nodes)
   {
     for (auto const & e : list_nodes)
       g_.emplace_back(e);
   }

  ~Graph()
  {
    std::for_each(edges_.begin(), edges_.end() ,[&] (auto & n) {
      delete n;
    });
  }


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
        Node* cur_node = *itB;

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

  bool RunBellmanFord(Node* s)
  {
    std::for_each(g_.begin(), g_.end() ,[&] (auto & n) {
      (*n).distance = -1;
      (*n).parent = nullptr;
    });

    s->distance = 0;

    auto const itE = edges_.end();

    for (std::size_t i = 0, len = edges_.size(); i < len; ++i)
      for (auto itB = edges_.begin(); itB != itE; ++itB)
        Relax( (*itB)->u, (*itB)->v, (*itB)->w );

    auto itB = edges_.begin();
    for (; itB != itE; ++itB)
      if ( (*itB)->v->distance > ( (*itB)->u->distance + (*itB)->w ) )
        return false;

    return true;
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

  void AddEdge(Node* u, Node* v, int w = -1)
  {
    edges_.emplace_back(new Edge(u, v, w));
  }

private:
  void DFSVisit(Node & u)
  {
    u.color = Color::GRAY;

    auto itB = u.neighbors.begin();
    auto const & itE = u.neighbors.cend();

    for (; itB != itE; ++itB) {
      Node* cur_node = *itB;

      if ( cur_node->color == Color::WHITE ) {
        cur_node->parent = &u;
        DFSVisit( *cur_node );
      }
    }
    u.color = Color::BLACK;
  }

  void Relax(Node* u, Node* v, int w)
  {
    if (v->distance > (u->distance + w) ) {
      v->distance = (u->distance + w);
      v->parent = u;
    }
  }

  std::vector<Node*> g_;
  std::vector<Edge*> edges_;
};

#endif // GRAPH_H
