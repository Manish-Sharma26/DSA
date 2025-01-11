#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool check(vector<int> arr, int x, int h)
  {
    long long cnt = 0;
    cout << x << "\n";
    for (auto i : arr)
    {
      if (i > x)
      {
        cnt += (i + (x - 1)) / x;
      }
      else
      {
        cnt += 1;
      }
    }
    return (cnt <= h);
  }
  int minEatingSpeed(vector<int> &vec, int h)
  {
    int low = 1, high = *max_element(vec.begin(), vec.end());
    while (low < high)
    {
      long long mid = low + (high - low) / 2;
      if (check(vec, mid, h))
      {
        high = mid;
      }
      else
        low = mid + 1;
    }
    return low;
  }
};

// another one (shorter one)
class Solution
{
public:
  int minEatingSpeed(vector<int> &vec, int h)
  {
    int low = 1, high = *max_element(vec.begin(), vec.end());
    while (low < high)
    {
      int mid = low + (high - low) / 2;
      int cnt = 0;
      for (auto i : vec)
        cnt += (i + (mid - 1)) / mid;
      if (cnt > h)
        low = mid + 1;
      else
        high = mid;
    }
    return low;
  }
};