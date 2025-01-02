#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
  {
    int n = grid.size();
    vector<int> rows(n, 0), cols(n, 0);
    int r = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        r = max(r, grid[i][j]);
        c = max(c, grid[j][i]);
      }
      rows[i] = r;
      r = 0;
      cols[i] = c;
      c = 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        ans += min(rows[i], cols[j]) - grid[i][j];
        // cout<<ans<<"\n";
      }
    }
    return ans;
  }
};