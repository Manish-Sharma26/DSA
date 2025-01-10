#include <bits/stdc++.h>
using namespace std;

// In O(mlog(n))
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
  int m = matrix.size();
  int n = matrix[0].size();
  bool flag = 0;
  for (int i = 0; i < m; i++)
  {
    if (binary_search(matrix[i].begin(), matrix[i].end(), target))
      flag = 1;
  }
  if (flag)
    return true;
  else
    return false;
}

// another one in O(m+n)
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
  int m = matrix.size();
  int n = matrix[0].size();
  int r = 0, c = n - 1;
  while (r < m && c >= 0)
  {
    if (matrix[r][c] == target)
      return true;
    else if (matrix[r][c] < target)
      r++;
    else
      c--;
  }
  return false;
}