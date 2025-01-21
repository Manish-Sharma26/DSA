#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maximumSumSubarray(vector<int> &arr, int k)
  {
    int n = arr.size();
    int i = 0, j = k;
    long long sum = accumulate(arr.begin(), arr.begin() + k, 0);
    long long mx = sum;
    while (j < n)
    {
      sum = sum - arr[i] + arr[j];
      mx = max(mx, sum);
      i++;
      j++;
    }
    return mx;
  }
};