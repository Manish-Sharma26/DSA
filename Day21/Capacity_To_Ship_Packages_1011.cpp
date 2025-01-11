#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int shipWithinDays(vector<int> &weights, int days)
  {
    long long low = *max_element(weights.begin(), weights.end()), high = accumulate(weights.begin(), weights.end(), 0);
    while (low < high)
    {
      int mid = low + (high - low) / 2;
      // cout<<mid<<"\n";
      int sm = 0, ans = 0, prev = -1;
      for (auto i : weights)
      {
        if (sm == mid)
        {
          sm = 0;
          ans++;
        }
        else if (sm > mid)
        {
          sm = prev;
          ans++;
        }
        sm += i;
        prev = i;
      }
      if (sm > mid)
        ans += 2;
      else
        ans++;
      cout << ans << "\n";
      if (ans > days)
      {
        low = mid + 1;
      }
      else
        high = mid;
    }
    return low;
  }
};