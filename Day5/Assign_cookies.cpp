#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s)
{
  int n = s.size();
  int m = g.size();

  sort(g.begin(), g.end());
  sort(s.begin(), s.end());
  int i = 0, j = 0;
  int ans = 0;
  while (i < m && j < n)
  {
    if (s[j] >= g[i])
    {
      ans++;
      i++;
      j++;
    }
    else
    {
      j++;
    }
  }
  return ans;
}