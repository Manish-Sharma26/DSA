#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int square(int n)
  {
    int cnt = 0;
    while (n)
    {
      int digit = n % 10;
      cnt += (digit * digit);
      n /= 10;
    }
    return cnt;
  }
  bool isHappy(int n)
  {
    map<int, int> mp;
    bool flag = 0;
    while (1)
    {
      if (n == 1)
      {
        flag = 1;
        break;
      }
      mp[n]++;
      int ans = square(n);
      // cout<<ans<<"\n";
      if (mp.find(ans) != mp.end())
      {
        return false;
        break;
      }
      else
      {
        mp[ans]++;
      }
      n = ans;
    }
    if (flag)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};
// optimal one without using extra space
//two pointer approach slow and fast hare tortoise
class Solution
{
public:
  int square(int n)
  {
    int cnt = 0;
    while (n)
    {
      int digit = n % 10;
      cnt += (digit * digit);
      n /= 10;
    }
    return cnt;
  }
  bool isHappy(int n)
  {
    int slow = square(n), fast = square(square(n));
    while (slow != fast)
    {
      if (fast == 1)
      {
        return true;
      }
      slow = square(slow);
      fast = square(square(fast));
    }
    return (slow == 1);
  }
};