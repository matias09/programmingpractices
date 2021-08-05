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
    ~Node()
    {
      std::for_each(neighbors.begin(), neighbors.end() ,[&] (auto & n) {
        delete n;
      });
    }

    void AddEdge(Node* n, int w)
    {
      neighbors.emplace_back( new Edge(n, w) );
    }

    bool operator < (Node const & rh)
    {
      if (this->distance <= rh.distance)
        return true;

      return false;
    }

    bool operator < (Node * rh)
    {
      if (this->distance <= rh->distance)
        return true;

      return false;
    }

    bool operator == (int rh_value)
    {
      if (this->value == rh_value)
        return true;

      return false;
    }

    bool operator == (Node const & rh)
    {
      if (  this->value == rh.value
         && this->distance == rh.distance
         && this->parent == rh.parent )
      {
        return true;
      }

      return false;
    }

    bool operator == (Node* rh)
    {
      if (  this->value == rh->value
         && this->distance == rh->distance
         && this->parent == rh->parent )
      {
        return true;
      }

      return false;
    }

    std::vector<Edge*> neighbors;
    Node* parent = nullptr;
    Color color = Color::WHITE;
    int distance = 0;
    int value;
  };

  struct Edge
  {
    Edge(Node* v, int w = -1)
      : v(v), w(w) {}

    Node* v;
    int w;
  };

   Graph() = default;

   Graph(const std::initializer_list<Node*> & list_nodes)
   {
     for (auto const & e : list_nodes)
       g_.emplace_back(e);
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
        Node* cur_node = (*itB)->v;

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
    InitializeSingleSource(*s);

    for (std::size_t ii = 0, len = g_.size(); ii < len; ++ii) {
      for (std::size_t i = 0, len = g_.size(); i < len; ++i) {
        auto itB = g_[i]->neighbors.begin();
        auto const & itE = g_[i]->neighbors.cend();

        for (; itB != itE; ++itB)
          Relax( g_[i], (*itB)->v, (*itB)->w );
      }
    }

    for (std::size_t i = 0, len = g_.size(); i < len; ++i) {
      auto itB = g_[i]->neighbors.begin();
      auto const & itE = g_[i]->neighbors.cend();

      for (; itB != itE; ++itB)
        if ( (*itB)->v->distance > ( g_[i]->distance + (*itB)->w ) )
          return false;
    }

    return true;
  }

  void RunDijkstra(Node* s, std::vector<Node*> & path, int const needle)
  {
    InitializeSingleSource(*s);

    std::priority_queue<Node*, std::vector<Node*>
                             , std::greater<Node*> > min_weights_nodes;

    std::for_each(g_.begin(), g_.end() ,[&] (auto & n) {
      min_weights_nodes.push( n );
    });

    while (not min_weights_nodes.empty() ) {
      Node* u = min_weights_nodes.top(); 
      min_weights_nodes.pop(); 

      path.emplace_back(u);

      auto itB = u->neighbors.begin();
      auto const & itE = u->neighbors.cend();

      for (; itB != itE; ++itB)
        Relax(u, (*itB)->v, (*itB)->w);
    }
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

private:
  void DFSVisit(Node & u)
  {
    u.color = Color::GRAY;

    auto itB = u.neighbors.begin();
    auto const & itE = u.neighbors.cend();

    for (; itB != itE; ++itB) {
      Node* cur_node = (*itB)->v;

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

  void InitializeSingleSource(Node & s)
  {
    std::for_each(g_.begin(), g_.end() ,[&] (auto & n) {
      (*n).parent = nullptr;
      (*n).color = Color::WHITE;
      (*n).distance = -1;
    });

    s.color = Color::GRAY;
    s.distance = 0;
  }

  std::vector<Node*> g_;
};

#endif // GRAPH_H
