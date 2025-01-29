#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int compute(vector<int> nums, int k)
  {
    int i = 0, j = 0;
    int ans = 0, cnt = 0;
    int n = nums.size();
    unordered_map<int, int> mp;
    while (j < n)
    {
      mp[nums[j]]++;
      while (mp.size() > k)
      {
        mp[nums[i]]--;
        if (mp[nums[i]] == 0)
          mp.erase(nums[i]);
        i++;
      }
      cnt += (j - i + 1);
      j++;
    }
    return cnt;
  }
  int subarraysWithKDistinct(vector<int> &nums, int k)
  {
    return compute(nums, k) - compute(nums, k - 1);
  }
};