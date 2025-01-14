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

// another one
class Solution
{
private:
  bool isValid(vector<int> &arr, int k, int timeTaken)
  {
    int n = arr.size(), curr = 0, painters = 0;
    for (int i = 0; i < n; i++)
    {
      if (arr[i] > timeTaken)
        return false;
      curr += arr[i];
      if (curr > timeTaken)
      {
        painters++;
        curr = arr[i];
      }
      else if (curr == timeTaken)
      {
        if (i != n - 1)
          painters++;
        curr = 0;
      }
    }
    return painters < k;
  }

public:
  int minTime(vector<int> &arr, int k)
  {
    int s = 0, e = 1e9, idx = 0;
    while (s <= e)
    {
      int m = s + (e - s) / 2;
      if (isValid(arr, k, m))
      {
        idx = m;
        e = m - 1;
      }
      else
      {
        s = m + 1;
      }
    }
    return idx;
  }
};