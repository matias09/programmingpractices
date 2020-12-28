#include <iostream>
#include <cmath>
#include <stdint.h>

//
// Input:    [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1]
//           [5,6,4]
//
// Expected: [6,6,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1]
// Output:   [5,6,4]

constexpr uint8_t BASE  = 10;
constexpr uint8_t POWER = 0;

struct ListNode {
  uint8_t val;
  ListNode *next;
  ListNode(uint8_t x) : val(x), next(NULL) {}
};

template <typename T>
void delete_list(T* l)
{
  T* aux = NULL;
  while (l!= NULL) {
    aux = l->next;

    delete l;
    l = NULL;

    l = aux;
  }

  delete l;
  l = NULL;
}

ListNode* add(ListNode* head, const int n)
{
  // std::cout << "-- " << __FUNCTION__  << "() --" << '\n';

  if (head == NULL) {
    head = new ListNode(n);
  } else {
    ListNode* b = head;

    while (head->next != NULL) {
      head = head->next;
    }

    head->next = new ListNode(n);
    head = b;
  }

  // std::cout << "\t -- n : " <<  n << '\n';

  return head;
}

void show_list(const ListNode* l)
{
  std::cout << "-- " << __FUNCTION__  << "() --" << '\n';

  std::cout << "\t -- l->val : ";
  while (l != NULL) {
    std::cout << static_cast<int>(l->val);
    l = l->next;
  }
  std::cout << '\n';
}

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
  {
    std::cout << "-- " << __FUNCTION__  << "() --" << '\n';

    if (l1 == NULL) {
      return l2;
    } else if (l2 == NULL) {
      return l1;
    }

    // int idx = 0;
    uint8_t sum = 0;
    bool l1_consumed  = false;
    bool l2_consumed  = false;
    bool last_number_grater_than_ten = true;

    ListNode* rl    = NULL;
    // ListNode* tmp_l = rl;

    while ( ! l1_consumed || ! l2_consumed ) {

      if (! l1_consumed) {
        sum += l1->val * std::pow(BASE, POWER);
        if (l1->next != NULL) {
          l1 = l1->next;
        } else {
          l1_consumed = true;
        }
      }

      // std::cout << "\t -- sum_1 : " << static_cast<int>(sum) << '\n';

     if (! l2_consumed) {
      sum += l2->val * std::pow(BASE, POWER);
        if (l2->next != NULL) {
          l2 = l2->next;
        } else {
          l2_consumed = true;
        }
      }

      // std::cout << "\t -- sum_2 : " << static_cast<int>(sum) << '\n';

      if ( sum < BASE ) {
        // std::cout << "\t -- sum_3 : " << static_cast<int>(sum)
                  // << " -- lower than 10" << '\n';
        rl = add(rl, sum);

        last_number_grater_than_ten = false;
        sum = 0;
      } else {
        // std::cout << "\t -- sum_3 : " << static_cast<int>((sum % BASE))
                  // << " -- greater than 10" << '\n';
        rl = add(rl, (sum % BASE) );

        sum /= BASE;
        // std::cout << "\t -- sum_4 : " << static_cast<int>((sum % BASE)) << '\n';
        // sum %= BASE;
        // std::cout << "\t -- sum_5 : " << static_cast<int>((sum % BASE)) << '\n';
        last_number_grater_than_ten = true;
      }

      // std::cout << '\n';
    }

    if (last_number_grater_than_ten) {
      // std::cout << "\n \t -- out of loop sum_5 : " << static_cast<int>(sum) << '\n';
      rl = add(rl, sum);
    }

    return rl;
  }
};

int main(int argc, char* args[])
{
  ListNode* l1 = NULL;
  ListNode* l2 = NULL;

  for (int i = 1; i < argc; ++i) {
    for (int j = 0; args[i][j] != '\0'; ++j) {
      if (args[i][j] == ',' ) {
        continue;
      }

      if (i == 1) {
        l1 = add(l1, static_cast<uint8_t>(args[i][j] - 48));
      } else {
        l2 = add(l2, static_cast<uint8_t>(args[i][j] - 48));
      }
    }
  }

  show_list(l1);
  show_list(l2);

  Solution s;
  ListNode* rl = s.addTwoNumbers(l1, l2);
  ListNode* b = rl;

  if (rl != NULL) {
    std::cout << "-- rl: ";
    while (rl != NULL) {
      std::cout << static_cast<int>(rl->val);
      rl = rl->next;
    }
  } else {
    std::cout << "-- Empty List Or Null element List..." << '\n';
  }

  rl = b;

  delete_list(l1);
  delete_list(l2);
  delete_list(rl);

  std::cout << '\n';
  return 0;
}
