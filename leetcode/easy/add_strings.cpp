// Problem Description:
//
// Given two non-negative integers num1 and num2 represented as string,
//   return the sum of num1 and num2.
//
// Note:
//
//     The length of both num1 and num2 is < 5100.
//     Both num1 and num2 contains only digits 0-9.
//     Both num1 and num2 does not contain any leading zero.
//     You must not use any built-in BigInteger library or
//      convert the inputs to integer directly.

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stdint.h>

constexpr uint8_t BASE  = 10;

class Solution
{
public:
  std::string addStrings(std::string num1, std::string num2)
  {
    uint16_t n1_length = num1.length();
    uint16_t n2_length = num2.length();

    if (n1_length == 0) {
      return num2;
    } else if (n2_length == 0) {
      return num1;
    }

    uint8_t idx = 0;
    uint16_t n1 = 0;
    uint16_t n2 = 0;

    idx = n1_length;
    std::for_each(num1.begin(), num1.end(), [&](char c){
      n1 += (c - 48) * std::pow(BASE, --idx);
    });

    idx = n2_length;
    std::for_each(num2.begin(), num2.end(), [&](char c){
      n2 += (c - 48) * std::pow(BASE, --idx);
    });

    uint16_t s = n1 + n2;

    int8_t  i = 0;
    char res[UINT16_MAX] = {'\0'};
    do {
      res[i] = ( s % BASE ) + 48;
      s /= BASE;

      ++i;
    } while (s != 0);

    std::string final_res = "";

    do {
      final_res += res[i--];
    } while (i > -1);

    return final_res;
  }
};

int main(int argc, char* args[])
{
  if (argc != 3) {
    std::cout << "[ERROR] Wrong number of arguments." << '\n'
              << "\t [number_1] [number_2] expected.";

    return 1;
  }

  Solution s;

  std::string n1 = args[1];
  std::string n2 = args[2];
  std::string n3 = s.addStrings(n1, n2);

  std::cout << "-- Result : " << n3 << '\n';

  return 0;
}
