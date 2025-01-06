#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<int> &arr, int k)
{

  // Your code here
  int low = 0, high = arr.size() - 1;
  int ans = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] <= k)
    {
      ans = mid;
      low = mid + 1;
    }
    else
      high = mid - 1;
  }
  return ans;
}