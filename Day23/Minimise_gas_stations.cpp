#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int gas(long double dist, vector<int> &arr)
  {
    int n = arr.size();
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
      int inbetween = (arr[i] - arr[i - 1]) / dist;
      if (inbetween * dist == (arr[i] - arr[i - 1]))
      {
        inbetween--;
      }
      cnt += inbetween;
    }
    return cnt;
  }
  double findSmallestMaxDist(vector<int> &stations, int k)
  {
    // Code here
    int n = stations.size();
    long double low = 0;
    long double high = 0;
    for (int i = 0; i < n - 1; i++)
    {
      high = max(high, (long double)(stations[i + 1] - stations[i]));
    }
    long double diff = 1e-6;
    while (high - low > diff)
    {
      long double mid = (high + low) / 2.0;
      int cnt = gas(mid, stations);
      if (cnt > k)
      {
        low = mid;
      }
      else
      {
        high = mid;
      }
    }
    return high;
  }
};
// another one
class Solution
{
private:
  bool isValid(vector<int> &stations, int k, double d)
  {
    int n = stations.size(), reqStations = 0;
    for (int i = 1; i < n; i++)
    {
      double dist = stations[i] - stations[i - 1];
      reqStations += dist / d;
      int temp = dist / d;
      if (dist != 0 && temp * d == dist)
        reqStations--;
    }
    return reqStations <= k;
  }

public:
  double findSmallestMaxDist(vector<int> &stations, int k)
  {
    double s = 0, e = 1e9, ans = 0;
    while (s <= e)
    {
      double mid = s + (e - s) / 2;
      if (isValid(stations, k, mid))
      {
        ans = mid;
        e = mid - 0.00001;
      }
      else
      {
        s = mid + 0.00001;
      }
    }
    return ans;
  }
};