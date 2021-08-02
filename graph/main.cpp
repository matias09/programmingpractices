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

  n1->AddNeighbors({n3, n4});
  n2->AddNeighbors({n5});
  n3->AddNeighbors({n3, n4, n5});
  n4->AddNeighbors({n1, n3});
  n5->AddNeighbors({n3, n2});

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

void TestGraphWithBellmanFordAlgorithm()
{
  Graph::Node* s = new Graph::Node(1);
  Graph::Node* t = new Graph::Node(2);
  Graph::Node* y = new Graph::Node(3);
  Graph::Node* x = new Graph::Node(4);
  Graph::Node* z = new Graph::Node(5);

  Graph g;

  g.AddEdge(s, t, 6);
  g.AddEdge(s, y, 7);

  g.AddEdge(t, x, 5);
  g.AddEdge(t, z, -4);
  g.AddEdge(t, y, 8);

  g.AddEdge(x, t, -2);

  g.AddEdge(z, s, 2);
  g.AddEdge(z, x, 7);

  g.AddEdge(y, x, -3);
  g.AddEdge(y, z, 9);

  std::cout << "-- Bellman Ford Algorithm \n";
  if ( g.RunBellmanFordSearch(s) )
    std::cout << "NO, Negative Cicle Path Found ";
  else
    std::cout << "Negative Cicle Path Found ";

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
  return 0;
}
