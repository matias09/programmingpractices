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

int main ()
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
  Graph::Node* end_node_path = g.RunBreathFirstSearch(n4, n2->value);

  if (end_node_path != nullptr)
    PrintPath( *(end_node_path) );
  else
    std::cout << "\t No Path Found ";

  std::cout << '\n';

  delete n5;
  delete n4;
  delete n3;
  delete n2;
  delete n1;

  return 0;
}
