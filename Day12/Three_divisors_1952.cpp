#include <bits/stdc++.h>
using namespace std;

// simple traversal O(n)
class Solution
{
public:
  bool isThree(int n)
  {
    int cnt = 1;
    for (int i = 2; i <= n; i++)
    {
      if (n % i == 0)
      {
        cnt++;
      }
      if (cnt > 3)
      {
        return false;
      }
    }
    if (cnt != 3)
    {
      return false;
    }
    else
    {
      return true;
    }
  }
};
// Better solution O(sqrt(n))
class Solution
{
public:
  bool isThree(int n)
  {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
      if (n % i == 0)
      {
        if (n / i != i)
          cnt++;
        cnt++;
      }
      if (cnt > 3)
      {
        return false;
      }
    }
    cout << cnt;
    if (cnt != 3)
    {
      return false;
    }
    else
    {
      return true;
    }
  }
};
// optimal solution O(n^(1/4))
// squares of prime will only have three divisors
class Solution
{
public:
  bool isprime(int n)
  {
    for (int i = 2; i * i <= n; i++)
    {
      if (n % i == 0)
        return false;
    }
    return true;
  }
  bool isThree(int n)
  {
    if (n != 1 && n != 2 && (int)sqrt(n) * sqrt(n) == n && isprime(sqrt(n)))
      return true;
    else
      return false;
  }
};