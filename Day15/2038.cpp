#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool winnerOfGame(string colors)
  {
    int alice = 0, bob = 0;
    int n = colors.size();
    int cnt = 0, cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
      if (colors[i] == 'A')
      {
        cnt1 = 0;
        cnt++;
        if (cnt >= 3)
          alice++;
      }
      else
      {
        cnt = 0;
        cnt1++;
        if (cnt1 >= 3)
          bob++;
      }
    }
    return (alice > bob);
  }
};

// another one
class Solution
{
public:
  bool winnerOfGame(string s)
  {
    int a = 0, b = 0;
    for (int i = 1; i < s.size() - 1; i++)
    {
      if (s[i - 1] == s[i] && s[i] == s[i + 1])
      {
        if (s[i] == 'A')
          a++;
        else
          b++;
      }
    }
    return a > b;
  }
};