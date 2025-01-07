#include <bits/stdc++.h>
using namespace std;

// O(sqrt(n)) approach
int arrangeCoins(int n)
{
  int i = 0;
  while (i < n)
  {
    i++;
    n = n - i;
  }
  return i;
}

// Math approach
int arrangeCoins(int n)
{
  return (int)(sqrt(2 * (long)n + 0.25) - 0.5);
}
// binary search
int arrangeCoins(int n)
{
  int low = 1, high = n;
  long long cnt = 0;

  while (low <= high)
  {
    long long mid = low + (high - low) / 2;
    cnt = mid * (mid + 1) / 2;
    cout << low << " " << mid << " " << high << "\n";
    if (cnt == n)
    {
      return mid;
    }
    else if (cnt < n)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return low - 1;
}

// binary search another variant beating 100%
int arrangeCoins(int n)
{
  int low = 1, high = n;
  long long cnt = 0;
  if (n == 1)
    return 1;
  while (low < high)
  {
    long long mid = low + (high - low) / 2;
    cnt = mid * (mid + 1) / 2;
    // cout<<low<<" "<<mid<<" "<<high<<"\n";
    if (cnt <= n)
    {
      low = mid + 1;
    }
    else
    {
      high = mid;
    }
  }
  return low - 1;
}
