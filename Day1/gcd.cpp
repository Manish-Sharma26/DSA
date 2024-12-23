#include <iostream>
using namespace std;
//recursive one 
int gcd(int a, int b)
{
  return b == 0 ? a : gcd(b, a % b);
}

//iterative one
int gcd1(int a, int b)
{
  while (a > 0 && b > 0)
  {
    if (a > b)
    {
      a = a % b;
    }
    else
    {
      b = b % a;
    }
    if (b == 0)
      return a;
    return b;
  }
}