#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> &arr, int target)
{
  int l = 0, h = arr.size() - 1;
  while (l <= h)
  {
    int m = l + (h - l) / 2;
    if (arr[m] == target)
      return true;
    else if (arr[l] == arr[m] && arr[m] == arr[h])
    {
      l++;
      h--;
    }
    else if (arr[l] <= arr[m])
    {
      if (arr[l] <= target && target <= arr[m])
        h = m - 1;
      else
        l = m + 1;
    }
    else
    {
      if (arr[m] <= target && target <= arr[h])
        l = m + 1;
      else
        h = m - 1;
    }
  }
  return false;
}