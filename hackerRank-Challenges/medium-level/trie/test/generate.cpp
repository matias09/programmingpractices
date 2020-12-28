#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using Words = std::vector<std::string>;
using WordsIter = std::vector<std::string>::iterator;

// Constants
const unsigned int ASCII_1 = 49;
const unsigned int ASCII_a = 97;
const unsigned int ASCII_z = 122;
const unsigned int MAX_CHAR_LENGTH = 21;
const unsigned int MIN_CHAR_LENGTH = 6;

// Prototypes
inline void InsertAddInput(std::fstream& file, WordsIter& itB, WordsIter& itE);
void InsertFindInput(std::fstream& file);

int main(int argc, char** args)
{
  std::cout << "\n\n";

  unsigned int times = 0;
  unsigned int wordsAmount = 0;
  unsigned int charsLength = 0;
  Words words;

  std::cout << "How many Test files cases will output ? - ";
  std::cin >> times;

  std::cout << "How many words for each case will be inserted ? - ";
  std::cin >> wordsAmount;

  std::srand((int)std::time(0));
  std::cout << "\n \n";

  // Loop how many Cases Files will be generated
  for (unsigned int i = 0; i < times; ++i)
  {
    std::string fileName = "contacts-cases-.txt";

    // Loop how many Words will be generated
    for (unsigned int j = 0; j < wordsAmount; ++j)
    {
      std::string word;

      // Get a random number between Max and Min values
      charsLength = (std::rand() % (MAX_CHAR_LENGTH - MIN_CHAR_LENGTH + 1) + MIN_CHAR_LENGTH) + 1;
      char random_char[charsLength];
      const unsigned short int charsLength_2 = charsLength - 1;


      // Generating random prefix
      for (int k = 0; k < charsLength_2; ++k)
      {
        // Get a random number between Max and Min values
        random_char[k] = std::rand() % (ASCII_z - ASCII_a + 1) + ASCII_a;
      }

      random_char[charsLength - 1] = '\0';
      word.append(random_char);
      words.push_back(word);
    }

    // Set File name with his index value
    fileName.insert(fileName.begin() + (fileName.size() - 4), static_cast<char>(i + ASCII_1));

    // Preparing File to put the random words
    std::fstream file(fileName.c_str(), std::ios::out);

    // Set the amount of command to use in the Trie Program
    file << (wordsAmount + (ASCII_z - ASCII_a)) + 1 << "\n";

    WordsIter itB = words.begin();
    WordsIter itE = words.end();

    // Sort words
    std::sort(itB, itE);

    // Reset Begin Iterator
    itB = words.begin();

    // Function to add 'add' random input command
    InsertAddInput(file, itB, itE);

    // Function to add 'find' random input command
    InsertFindInput(file);

    // Reset the string vector
    words.clear();

    // Closing Cases File
    file.close();
  }

  std::cout << "--- Technically ends well. \n \n";
  return 0;
}

inline void InsertAddInput(std::fstream& file, WordsIter& itB, WordsIter& itE)
{
  // Writing part of the test
  for (; itB != itE; ++itB)
  {
    file << "add " << *itB << "\n";
  }
}

void InsertFindInput(std::fstream& file)
{
  const unsigned int lastLetter = ASCII_z + 1;
  // Writing part of the test
  for (unsigned int i = ASCII_a; i < lastLetter; ++i)
  {
    file << "find " << static_cast<char>(i) << "\n";
  }
}
