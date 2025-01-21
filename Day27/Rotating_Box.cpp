#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>> &boxGrid)
  {
    int m = boxGrid.size();
    int n = boxGrid[0].size();
    // int ind =0;
    vector<vector<char>> ans(n, vector<char>(m, ' '));
    int p1 = 0, p2 = 0;
    for (int i = m - 1; i >= 0; i--)
    {
      p1 = 0;
      for (int j = 0; j < n; j++)
      {
        if (boxGrid[i][j] == '#')
        {
          continue;
        }
        else if (boxGrid[i][j] == '.')
        {
          swap(boxGrid[i][j], boxGrid[i][p1]);
          p1++;
        }
        else
        {
          p1 = j + 1;
        }
      }

      for (int j = 0; j < n; j++)
      {
        ans[j][m - i - 1] = boxGrid[i][j];
      }
      // ind++;
    }
    return ans;
  }
};