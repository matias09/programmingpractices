#include "graph.h"

#include <iostream>
#include <vector>
#include <algorithm>

void PrintPath(Graph::Node const & n)
{
  if (n.parent != nullptr)
    PrintPath( *(n).parent );

  std::cout <<  n.value << ' ';
}

void TestGraphWithBreadthFirstSearchAlgorithm()
{
  Graph::Node* n1 = new Graph::Node(1);
  Graph::Node* n2 = new Graph::Node(2);
  Graph::Node* n3 = new Graph::Node(3);
  Graph::Node* n4 = new Graph::Node(4);
  Graph::Node* n5 = new Graph::Node(5);

  n1->AddEdge(n3, 1);
  n1->AddEdge(n4, 1);

  n2->AddEdge(n5, 1);

  n3->AddEdge(n1, 1);
  n3->AddEdge(n4, 1);
  n3->AddEdge(n5, 1);

  n4->AddEdge(n1, 1);
  n4->AddEdge(n3, 1);

  n5->AddEdge(n3, 1);
  n5->AddEdge(n2, 1);

  Graph g{ n1, n2, n3, n4, n5 };

  Graph::Node* end_node_path = g.RunBreadthFirstSearch(n4, n2->value);

  std::cout << "-- Breadth First Search Algorithm \n";
  if (end_node_path != nullptr)
    PrintPath( *(end_node_path) );
  else
    std::cout << "No Path Found ";

  std::cout << '\n';

  delete n5;
  delete n4;
  delete n3;
  delete n2;
  delete n1;
}

void TestGraphWithDijkstraAlgorithm()
{
  Graph::Node* s = new Graph::Node(1);
  Graph::Node* t = new Graph::Node(2);
  Graph::Node* y = new Graph::Node(3);
  Graph::Node* x = new Graph::Node(4);
  Graph::Node* z = new Graph::Node(5);

  Graph g{s, t, y, x, z};

  s->AddEdge(t, 10);
  s->AddEdge(y, 5);

  t->AddEdge(x, 1);
  t->AddEdge(y, 2);

  x->AddEdge(z, 4);

  y->AddEdge(t, 3);
  y->AddEdge(x, 9);
  y->AddEdge(z, 2);

  z->AddEdge(s, 7);
  z->AddEdge(x, 6);

  std::vector<Graph::Node*> path;
  g.RunDijkstra(s, path, y->value);

  std::cout << "-- Dijkstra Search Algorithm \n";
  std::for_each(path.begin(), path.end() ,[&] (auto & n) {
      std::cout << "Current Node " << n->value << '\n'
                << '\t' << "Parents: ";

      Graph::Node* p = n->parent;
      while (p != nullptr) {
        std::cout << p->value << ' ';
        p = p->parent;
      }
      std::cout << '\n';
  });

  std::cout << '\n';

  delete z;
  delete x;
  delete y;
  delete t;
  delete s;
}


void TestGraphWithBellmanFordAlgorithm()
{
  Graph::Node* s = new Graph::Node(1);
  Graph::Node* t = new Graph::Node(2);
  Graph::Node* y = new Graph::Node(3);
  Graph::Node* x = new Graph::Node(4);
  Graph::Node* z = new Graph::Node(5);

  Graph g{s, t, y, x, z};

  s->AddEdge(t, 6);
  s->AddEdge(y, 7);

  t->AddEdge(x, 5);
  t->AddEdge(z, -4);
  t->AddEdge(y, 8);

  x->AddEdge(t, -2);

  z->AddEdge(s, 2);
  z->AddEdge(x, 7);

  y->AddEdge(x, -3);
  y->AddEdge(z, 9);

  std::cout << "-- Bellman Ford Algorithm \n";
  if ( g.RunBellmanFord(s) ) {
    std::cout << "NO, Negative Cicle Path Found ";
    PrintPath( *s );
  } else {
    std::cout << "Negative Cicle Path Found ";
  }

  std::cout << '\n';

  delete z;
  delete x;
  delete y;
  delete t;
  delete s;
}

int main ()
{
  TestGraphWithBreadthFirstSearchAlgorithm();
  TestGraphWithBellmanFordAlgorithm();
  TestGraphWithDijkstraAlgorithm();
  return 0;
}
