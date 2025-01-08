#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
  int n = matrix.size();
  int m = matrix[0].size();
  for (int i = 1; i < n; i++)
  {
    matrix[0].insert(matrix[0].end(), matrix[i].begin(), matrix[i].end());
  }
  int low = 0, high = matrix[0].size() - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (matrix[0][mid] == target)
      return true;
    else if (matrix[0][mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return false;
}

// alternative without using extra space
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
  int n = matrix.size();
  int m = matrix[0].size();
  int low = 0, high = n * m - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int i = mid / m;
    int j = mid % m;
    if (matrix[i][j] == target)
      return true;
    else if (matrix[i][j] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return false;
}