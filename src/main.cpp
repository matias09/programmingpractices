// ------------------------- T O D O  T H I N G S -------------------------- //
// TODO : Fix Balance Process
// TODO : Create test files and save results in .txt files
// ------------------------- T O D O  T H I N G S -------------------------- //
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
#include "../headers/BinaryTree.h"

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
#if not define (_WIN64) || not define (_WIN32)
  std::cout << "\t- (c) Clear Screen .\n";
#endif // _WIN32 || _WIN64
  std::cout << "\t- (q) Exit .\n\n";
  std::cout << " - Option : ";
}

int main(int argsc, char** args)
{
  char o;
  std::unique_ptr<BinaryTree> binaryTree = std::unique_ptr<BinaryTree>(new BinaryTree());

  // level 0
  binaryTree->Insert(500);

  // level 1
  binaryTree->Insert(225);
  binaryTree->Insert(725);
//
//  // level 2
  binaryTree->Insert(122);
//  binaryTree->Insert(370);
//  binaryTree->Insert(600);
//  binaryTree->Insert(900);
//
//  // level 3
  binaryTree->Insert(90);
//  binaryTree->Insert(190);
//  binaryTree->Insert(280);
//  binaryTree->Insert(425);
//  binaryTree->Insert(550);
//  binaryTree->Insert(650);
//  binaryTree->Insert(800);
//  binaryTree->Insert(2000);
//
//  // level 4
//  binaryTree->Insert(45);
//  binaryTree->Insert(108);
//  binaryTree->Insert(130);
//  binaryTree->Insert(210);

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
        int n;
        std::cout << " - Insert a Number to Erase : ";
        std::cin >> n;

        binaryTree->Erase(n);
        break;
      }
#if not define (_WIN64) || not define (_WIN32)
      case MENU_OPTIONS::OPT_CLEAN_SCREEN:
      {
        ClearScreen();
        break;
      }
#endif // _WIN32 || _WIN64
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

  // Technically with this Method Call I would Leak Memory.
  // I have to improve this using iteration in the
  // Destructor Method to release memory.
  binaryTree->ReleaseTree();

  std::cout << "Number of Nodes : " << binaryTree->GetNumberOfElements() << "\n";

  return 0;
}
