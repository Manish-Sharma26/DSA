#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// brute
class Solution
{
public:
  int countKDifference(vector<int> &nums, int k)
  {
    int n = nums.size();
    // int i,j;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (abs(nums[i] - nums[j]) == k)
          cnt++;
      }
    }
    return cnt;
  }
};
// better one using map
class Solution
{
public:
  int countKDifference(vector<int> &nums, int k)
  {
    map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (mp.find(nums[i] + k) != mp.end())
      {
        ans += mp[nums[i] + k];
      }
      if (mp.find(nums[i] - k) != mp.end())
      {
        ans += mp[nums[i] - k];
      }
      mp[nums[i]]++;
    }
    return ans;
  }
};