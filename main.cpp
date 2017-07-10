// ------------------------- T O D O  T H I N G S --------------------------------------------------------------- //
// TODO : Implement Balance Process when the Average Node is the Head Node.
// TODO : Fix Balance Process when there are less nodes from the Lowest side.
// TODO : Improve EraseNode() Method because there are to many IF statements. Try to separate in more functions
// TODO : Use Precompiler Functions to choose when send Debug Output.
// TODO : Create test files
// ------------------------- T O D O  T H I N G S --------------------------------------------------------------- //
#include <string.h>
#include <iostream>
#include <memory>

// Code to clear screen on Linux

void ClearScreen()
{
#if _WIN32
#else
  std::cout << "\033[2J\033[1;1H";
#endif
}
// End

// Own Classes
#include "BinaryTree.h"

// Options
enum MENU_OPTIONS
{
  OPT_ADD = 'a',
  OPT_SHOW = 's',
  OPT_ERASE = 'e',
  OPT_CLEAN_SCREEN = 'c',
  OPT_QUIT = 'q',
};

void ShowMenu()
{
  std::cout << "Choose an Option from the Menu: \n";
  std::cout << "\t- (a) Add a Node .\n";
  std::cout << "\t- (s) Show Nodes .\n";
  std::cout << "\t- (e) Erase a Node .\n";
  std::cout << "\t- (c) Clear Screen .\n";
  std::cout << "\t- (q) Exit .\n\n";
  std::cout << " - Option : ";
}
int main(int argsc, char** args)
{
  char o;
  std::unique_ptr<BinaryTree> binaryTree = std::unique_ptr<BinaryTree>(new BinaryTree());

  binaryTree->Insert(500);

  std::cout << "Number of Nodes : " << binaryTree->GetNumberOfElements() << "\n";
  binaryTree->ShowElements();
  std::cout << "\n \n";

  do
  {
    ShowMenu();
    std::cin >> o;

    std::cout << "\n \n";
    switch (o)
    {
      case MENU_OPTIONS::OPT_SHOW:
      {
        std::cout << " - Number of Nodes : " << binaryTree->GetNumberOfElements() << "\n";
        binaryTree->ShowElements();
        break;
      }
      case MENU_OPTIONS::OPT_ADD:
      {
        int n;
        std::cout << " - Insert a Number to Add : ";
        std::cin >> n;

        binaryTree->Insert(n);
        break;
      }
      case MENU_OPTIONS::OPT_ERASE:
      {
//        int n;
//        std::cout << " - Insert a Number to Erase : ";
//        std::cin >> n;
//
//        binaryTree->Erase(n);
        std::cout << " - Option Not Available. ";
        break;
      }
      case MENU_OPTIONS::OPT_CLEAN_SCREEN:
      {
        ClearScreen();
        break;
      }
      case MENU_OPTIONS::OPT_QUIT:
      {
        break;
      }
      default:
      {
        std::cout << "\n/--------------/ \n";
        std::cout << " - Wrong Option -";
        std::cout << "\n/--------------/ \n";
      }
    }
    std::cout << "\n \n";
  } while (o != MENU_OPTIONS::OPT_QUIT);

  // Technically with this Method Call I will not Leak Memory.
  binaryTree->ReleaseTree();

  std::cout << "Number of Nodes : " << binaryTree->GetNumberOfElements() << "\n";

  return 0;
}
