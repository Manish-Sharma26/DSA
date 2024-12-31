#include <bits/stdc++.h>
using namespace std;
// using sorting
class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    sort(strs.begin(), strs.end());
    string ans = "";
    int m = strs.size();
    int n = strs[0].length();
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
      char ch = strs[0][i];
      for (int j = 1; j < m; j++)
      {
        if (ch != strs[j][i])
        {
          flag = 1;
          break;
        }
      }
      if (flag)
      {
        break;
      }
      else
      {
        ans += ch;
      }
    }
    return ans;
  }
};

// without sorting
class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    string ans = "";
    int m = strs.size();
    int n = strs[0].length();
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
      char ch = strs[0][i];
      for (int j = 1; j < m; j++)
      {
        if (strs[j].length() < i)
        {
          flag = 1;
          break;
        }
        if (ch != strs[j][i])
        {
          flag = 1;
          break;
        }
      }
      if (flag)
      {
        break;
      }
      else
      {
        ans += ch;
      }
    }
    return ans;
  }
};