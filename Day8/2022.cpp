#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
  {
    vector<vector<int>> vec;
    int size = original.size();
    if (m * n != size)
    {
      return vec;
    }
    else
    {
      vec.resize(m, vector<int>(n));
      for (int i = 0; i < m; i++)
      {
        vec[i].assign(original.begin() + n * i, original.begin() + n * (i + 1));
      }
    }
    return vec;
  }
};
// another one
class Solution
{
public:
  vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
  {
    if (m * n != original.size())
    {
      return {};
    }
    vector<vector<int>> ans(m, vector<int>(n));
    int ind = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        ans[i][j] = original[ind++];
      }
    }
    return ans;
  }
};