#include <bits/stdc++.h>
using namespace std;

int minTime(vector<int> &arr, int k)
{
  // code here
  // return minimum time
  int n = arr.size();
  int store = k;
  int low = *max_element(arr.begin(), arr.end()), high = accumulate(arr.begin(), arr.end(), 0);
  while (low <= high)
  {
    k = store;
    int mid = low + (high - low) / 2;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += arr[i];
      if (sum > mid)
      {
        sum = arr[i];
        k--;
      }
    }
    if (sum)
      k--;
    if (k < 0)
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