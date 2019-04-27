#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <stack>

//const unsigned int MAX_VALUE = -1;

class Node {
public:
  Node() = default;
  Node(char param_v) : v(param_v) {}

  Node(const Node &rh) {
    if (rh.up != nullptr) this->up = new Node(rh.up->v);
    if (rh.down != nullptr) this->down = new Node(rh.down->v);
    if (rh.right != nullptr) this->right = new Node(rh.right->v);
    if (rh.left != nullptr) this->left = new Node(rh.left->v);

    this->v = rh.v;
    this->distance = rh.distance;
  }

/*
  Node operator=(const Node &rh) {
    if (rh.up != nullptr) this.up = new Node(rh.up.v);
    if (rh.down != nullptr) this.down = new Node(rh.down.v);
    if (rh.right != nullptr) this.right = new Node(rh.right.v);
    if (rh.left != nullptr) this.left = new Node(rh.left.v);

    return this;
  }
  */

  ~Node() {
    if (up != nullptr) delete up;
    if (down != nullptr) delete down;
    if (right != nullptr) delete right;
    if (left != nullptr) delete left;
  }


  int v                 = 0;
  unsigned int distance = 0;
  //unsigned int distance = MAX_VALUE;
  Node *up              = nullptr;
  Node *down            = nullptr;
  Node *left            = nullptr;
  Node *right           = nullptr;
};

void FindShortestPath(const Node &src, const Node &dst, std::queue<const Node*> &steps) {
  if (src.v == dst.v) steps.push(&src);

  std::stack<Node*> node_history;
  Node current = new Node(src);

  // 1  2  3  4  5
  // 6  7  8  9  10
  // 11 12 13 14 15

  for (;;) {
    // Checks if we get where we want
    if (current->v == dst.v) {
      steps.push(current);
      break;
    }

    // check upper node
    if (current->up != nullptr) {
      current->up->distance = current->distance + 1;
      current = current->up;

      steps.push(current);
      node_history.push_back(current);
    }

    // all nodes related to current
    // were visited. Turn back to
    // previous Node.
    current = node_history.pop_back();

    // if node_history is empty.
    // Technically We Found our
    // Target Node, so we get out.
    if (node_history.size() == 0) break;
  }
}

int main() {
  Node *n1  = new Node(1);
  Node *n2  = new Node(2);
  Node *n3  = new Node(3);
  Node *n4  = new Node(4);
  Node *n5  = new Node(5);

  Node *n6  = new Node(6);
  Node *n7  = new Node(7);
  Node *n8  = new Node(8);
  Node *n9  = new Node(9);
  Node *n10 = new Node(10);

  Node *n11 = new Node(11);
  Node *n12 = new Node(12);
  Node *n13 = new Node(13);
  Node *n14 = new Node(14);
  Node *n15 = new Node(15);

/*
      // First Row      // Second Row      // Third Row
      n1->right = n2;   n6->right = n7;    n11->right = n12;
      n1->down  = n6;   n6->down  = n11;   n11->up    = n6;
                        n6->up    = n1;

      n2->left  = n1;   n7->left  = n6;    n12->left  = n11;
      n2->right = n3;   n7->right = n8;    n12->right = n13;
      n2->down  = n7;   n7->down  = n12;   n12->up    = n7;
                        n7->up    = n2;

      n3->left  = n2;   n8->left  = n7;    n13->left  = n12;
      n3->right = n4;   n8->right = n9;    n13->right = n14;
      n3->down  = n8;   n8->down  = n13;   n13->up    = n8;
                        n8->up    = n3;

      n4->left  = n3;   n9->left  = n8;    n14->left  = n13;
      n4->right = n5;   n9->right = n10;   n14->right = n15;
      n4->down  = n9;   n9->down  = n14;   n14->up    = n9;
                        n9->up    = n4;

                        n10->left  = n9;
      n5->left  = n4;   n10->down  = n15;   n15->left  = n14;
      n5->down  = n10;  n10->up    = n5;    n15->up    = n10;
*/

  // First Row      // Second Row      // Third Row
  n1->right = n2;   n6->right = n7;    n11->right = n12;
  n1->down  = n6;   n6->down  = n11;   n11->up    = n6;
                    n6->up    = n1;

  n2->left  = n1;   n7->left  = n6;    n12->left  = n11;
  n2->right = n3;   n7->right = n8;    n12->right = n13;
  n2->down  = n7;   n7->down  = n12;   n12->up    = n7;
                    n7->up    = n2;

  n3->left  = n2;   n8->left  = n7;    n13->left  = n12;
  n3->right = n4;   n8->right = n9;    n13->right = n14;
  n3->down  = n8;   n8->down  = n13;   n13->up    = n8;
                    n8->up    = n3;

  n4->left  = n3;   n9->left  = n8;    n14->left  = n13;
  n4->right = n5;   n9->right = n10;   n14->right = n15;
  n4->down  = n9;   n9->down  = n14;   n14->up    = n9;
                    n9->up    = n4;

                    n10->left  = n9;
  n5->left  = n4;   n10->down  = n15;   n15->left  = n14;
  n5->down  = n10;  n10->up    = n5;    n15->up    = n10;

  std::queue<const Node*> steps;
  FindShortestPath(*n1, *n7, steps);

  // Show shortest path node sequence

  return 0;
}
