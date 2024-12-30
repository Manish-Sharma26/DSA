#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minPartitions(string s)
  {
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      ans = max(ans, s[i] - 48);
      if (ans == 9)
      {
        break;
      }
    }
    return ans;
  }
};
// concise one
class Solution
{
public:
  int minPartitions(string n)
  {
    int ans = 0;
    for (auto i : n)
      ans = max(ans, i - 48);
    return ans;
  }
};
