#include <bits/stdc++.h>
using namespace std;

int aggressiveCows(vector<int> &stalls, int k)
{

  int n = stalls.size();
  int store = k;
  sort(stalls.begin(), stalls.end());
  int low = 1, high = stalls[n - 1] - stalls[0];
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int last = stalls[0];
    k = store - 1;
    for (int i = 1; i < n; i++)
    {
      if (stalls[i] - last >= mid)
      {
        k--;
        last = stalls[i];
      }
    }
    // cout<<mid <<" "<<k<<"\n";
    if (k > 0)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return high;
}