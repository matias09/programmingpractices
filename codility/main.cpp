#include <iostream>
#include <vector>
#include <limits>
#include <math.h>

//#include <stdint.h> // This is for include int32_t and int64_t

#define NUMBER_LIMIT 100000

#ifdef DEBUG
#define LOG_TEXT_VAL(m, v)    \
  std::cout << m << v << "\n";
#else
#define LOG_TEXT_VAL(m, v)
#endif

typedef unsigned long int UInt;
typedef long int          Int;

Int GetContainerAddition(const std::vector<Int> &A, const UInt &p, const UInt &r)
{
  Int t = 0;

  for (UInt i = p; i < r; ++i)
    t += A[i];

  return t;
}

UInt solution(const std::vector<Int>& A)
{
  UInt aSize     = A.size();
  UInt p         = 0;
  UInt q         = aSize / 2;
  UInt r         = aSize;
  Int t1         = 0;
  Int t2         = 0;
  Int tmp_t1     = 0;
  Int tmp_t2     = 0;
  Int tmp_diff   = 0;
  Int diff       = std::numeric_limits<Int>::max();

#ifdef DEBUG
  unsigned int not_infinite_loop = 20;
  std::cout << "\nNot infinite loop : " << not_infinite_loop << "\n";
#endif

  do
  {
    t1       = GetContainerAddition(A, p, q) + tmp_t1;
    t2       = GetContainerAddition(A, q, r) + tmp_t2;
    tmp_diff = std::abs(t1 - t2);

    if (tmp_diff < diff)
      diff = tmp_diff;

#ifdef DEBUG
    std::cout << "Not infinite loop : " << not_infinite_loop - 1 
              << "\t diff : " << diff 
              << "\t p : " << p 
              << "\t q : " << q 
              << "\t r : " << r 
              << "\t t1 : " << t1 
              << "\t t2 : " << t2 << "\n" ;
#endif

    if (t1 > t2)
    {
      tmp_t2 = t2;
      r = q;
      q = (q - p) / 2;
    }
    else
    {
      tmp_t1 = t1;
      p  = q;
      q += (r - q)  / 2;
    }

#ifdef DEBUG
    --not_infinite_loop;
  } while ( not_infinite_loop != 0 );
#else
  } while (diff != 0 && ( p != r && (r - 1) != p && (r - 1) != 0 ));
#endif

  return diff;
}

int main(int argc, char** args)
{
  std::cout << "\n--------------------------------------\n";
  std::vector<Int> container = {3,5,1,1,2,5,3,4,4,4,4,4};

  Int containerSize = container.size();
  for (int i = 0; i < containerSize; ++i)
    std::cout << container[i] << " ";

  if (container.size() < NUMBER_LIMIT)
  {
    Int res = solution(container);
    std::cout << "\n Solution : " << res << "\n";
  }
  else
  {
    std::cout << "Container Size is bigger than the Allowed Numbers Amount \n";
  }

  std::cout << "\n--------------------------------------\n";
  return 0;
}
