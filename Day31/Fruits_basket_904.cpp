#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int totalFruit(vector<int> &fruits)
  {
    int n = fruits.size();
    int i = 0, j = 0;
    int cnt = 0, ans = 0;
    map<int, int> mp;
    while (j < n)
    {
      mp[fruits[j]]++;
      if (mp.size() > 2)
      {
        cnt = j - i;
        ans = max(cnt, ans);
        mp[fruits[i]]--;
        if (mp[fruits[i]] == 0)
        {
          mp.erase(fruits[i]);
        }
        i++;
        mp[fruits[j]]--;
      }
      else
      {
        j++;
      }
    }
    ans = max(ans, j - i);
    return ans;
  }
};

// optimal one
class Solution
{
public:
  int totalFruit(vector<int> &fruits)
  {
    int n = fruits.size();
    int i = 0, j = 0;
    int cnt = 0, ans = 0;
    unordered_map<int, int> mp;
    while (j < n)
    {
      mp[fruits[j]]++;
      if (mp.size() > 2)
      {
        mp[fruits[i]]--;
        if (mp[fruits[i]] == 0)
        {
          mp.erase(fruits[i]);
        }
        i++;
      }
      if (mp.size() <= 2)
      {
        ans = max(ans, j - i + 1);
      }
      j++;
    }
    // ans = max(ans, j-i);
    return ans;
  }
};