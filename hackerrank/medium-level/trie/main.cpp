#include <iostream>
#include <map>
#include <limits>
#include <sstream>

// ------------------------------------------------------------------------------------------
// Helpers Function Prototypes
// ------------------------------------------------------------------------------------------
void SetValues(std::string &op, std::string &contact);
bool ValidateStrings(std::string &input);

// ------------------------------------------------------------------------------------------
// ContactList Class Declaration
// ------------------------------------------------------------------------------------------
class ContactList
{
private:
  // Declare Trie Node
  struct Node
  {
    Node() : isCompleteWord(false) {}
    ~Node();

    std::map<char, Node*> childs;
    bool isCompleteWord;
  };

public:
  ContactList(){ mRoot = new Node(); };
  ~ContactList(){ delete mRoot; };

  // Methods Require by Hacker Rank Exercise
  void add(const std::string& name);
  int find(const std::string& name);
  //------------------------------------------

private:
  void SearchForMatchingWordsRecursively(Node& actualNode, unsigned int& matchCounter);

  Node* mRoot;
};


// ------------------------------------------------------------------------------------------
// ContactList Class Definition
// ------------------------------------------------------------------------------------------
ContactList::Node::~Node()
{
  std::map<char, Node*>::iterator itB = childs.begin();
  std::map<char, Node*>::iterator itE = childs.end();
  for (; itB != itE; ++itB)
  {
    delete itB->second;
  }
}

void ContactList::SearchForMatchingWordsRecursively(Node& actualNode, unsigned int& matchCounter)
{
  std::map<char, Node*>::const_iterator itB = actualNode.childs.begin();
  std::map<char, Node*>::const_iterator itE = actualNode.childs.end();
  for (; itB != itE; ++itB)
  {
    SearchForMatchingWordsRecursively(*(itB->second), matchCounter);
  }

  if (actualNode.isCompleteWord == true)
  {
    ++matchCounter;
  }
}

void ContactList::add(const std::string& name)
{
  std::map<char, Node*>::const_iterator itE = mRoot->childs.end();
  const unsigned int nameSize = name.size();
  Node* actualNode = mRoot;

  for (unsigned int i = 0; i < nameSize; ++i)
  {
    if (actualNode->childs.find(name[i]) == itE)
    {
      Node* newChild = new Node();
      actualNode->childs.insert(std::pair<char, Node*>(name[i], newChild));
      actualNode = newChild;
    }
    else
    {
      actualNode = actualNode->childs.find(name[i])->second;
    }
    itE = actualNode->childs.end();
  }

  actualNode->isCompleteWord = true;
}

int ContactList::find(const std::string& name)
{
  bool breakSearch = false;
  const unsigned int charsAmount = name.size();
  unsigned int matchCounter = 0;
  std::map<char,Node*>::const_iterator itE;
  Node* actualNode = mRoot;

  for (unsigned int i = 0; i < charsAmount; ++i)
  {
    itE = actualNode->childs.end();
    if (actualNode->childs.find(name[i]) != itE)
    {
      actualNode = actualNode->childs.find(name[i])->second;
    }
    else
    {
      matchCounter = 0;
      breakSearch = true;
      break;
    }
  }

  if (breakSearch != true)
  {
    SearchForMatchingWordsRecursively(*actualNode, matchCounter);
  }

  return matchCounter;
}


// ------------------------------------------------------------------------------------------
// Main
// ------------------------------------------------------------------------------------------
int main(int argc, char** args)
{
  const unsigned int CODE_SUCCESS = 0;
  int n;
  std::string input;
  ContactList* cl = new ContactList();

  std::getline(std::cin, input);
  if (input.length() < 1 || input.length() > 100000)
    return CODE_SUCCESS;

  std::stringstream(input) >> n;
  if (n < 1 || n > 100000)
    return CODE_SUCCESS;

  for(int a0 = 0; a0 < n; ++a0)
  {
    std::string contact;

    std::getline(std::cin, input);
    SetValues(input, contact);

    if (ValidateStrings(input) == true && ValidateStrings(contact) == true)
    {
      if (input.compare("add") == 0)
      {
        cl->add(contact);
      }
      else if (input.compare("find") == 0)
      {
        std::cout << cl->find(contact) << '\n';
      }
    }
  }

  delete cl;
  cl = NULL;

  return CODE_SUCCESS;
}

// ------------------------------------------------------------------------------------------
// Helpers Function Definitions
// ------------------------------------------------------------------------------------------

void SetValues(std::string &op, std::string &contact)
{
  size_t space_pos = 0;

  space_pos = op.find(" ");
  if (space_pos != std::string::npos)
  {
    contact = op.substr(space_pos + 1);
    op = op.substr(0, space_pos);
  }
}

bool ValidateStrings(std::string &input)
{
  bool   isValid       = true;
  size_t string_length = input.length();

  if (string_length > 0 && string_length < 22)
  {
    std::string::const_iterator itB = input.begin();
    std::string::const_iterator itE = input.end();

    for (; itB != itE; ++itB)
    {
      if ( *itB < 65 || (*itB > 90 && *itB < 97) || *itB > 122)
        isValid = false;
    }
  }
  else
  {
    isValid = false;
  }

  return isValid;
}
