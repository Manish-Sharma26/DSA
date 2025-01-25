#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numberOfAlternatingGroups(vector<int> &colors)
  {
    int n = colors.size();
    colors.insert(colors.begin(), colors[n - 1]);
    colors.insert(colors.end(), colors[1]);
    n += 2;
    int ans = 0;
    for (int i = 0; i < n - 2; i++)
    {
      if ((colors[i] == 1 && colors[i + 1] == 0 && colors[i + 2] == 1) || (colors[i] == 0 && colors[i + 1] == 1 && colors[i + 2] == 0))
      {
        ans++;
      }
    }
    return ans;
  }
};
