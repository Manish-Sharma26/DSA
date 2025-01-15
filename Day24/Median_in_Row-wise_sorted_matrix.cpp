#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int median(vector<vector<int>> &mat)
  {
    // code here
    int m = mat.size();
    int n = mat[0].size();
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      minVal = min(mat[i][0], minVal);
      maxVal = max(mat[i][n - 1], maxVal);
    }
    int ind = (m * n + 1) / 2;
    // cout<<minVal<<" "<<maxVal<<"\n";
    int low = minVal, high = maxVal;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      int cnt = 0;
      for (int i = 0; i < m; i++)
      {
        cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
      }
      cout << mid << " " << cnt << "\n";
      if (cnt < ind)
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
    return low;
  }
};