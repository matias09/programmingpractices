#ifndef BINARY_TREE
#define BINARY_TREE

typedef struct Node
{
  Node(unsigned int pn) : n(pn)
  {
    mLeftDirectionTaken = false;
    mRightDirectionTaken = false;
    mLower = nullptr;
    mGreater = nullptr;
  }
  ~Node(){}

  bool mLeftDirectionTaken;
  bool mRightDirectionTaken;
  unsigned int n;
  Node* mLower;
  Node* mGreater;
} Node;

class BinaryTree
{
  public:
    BinaryTree();
    ~BinaryTree();

    const unsigned int GetNumberOfElements() const { return mCount; }
    void Insert(const int n);
    void ShowElements();
  private:
    void ExecuteBalance();
    void ReleaseNodes();
    void ShowNode(Node* node);
    void SaveNode(Node* node, const int n, unsigned int& levelCounter);

    unsigned int mCountLowestNumbers;
    unsigned int mCountGreatestNumbers;
    unsigned int mCount;
    Node* mHeadNode;
};

#endif // BINARY_TREE
