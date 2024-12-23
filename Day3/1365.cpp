#include <bits/stdc++.h>
using namespace std;

// brute force
vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
  vector<int> ans;
  int n = nums.size();
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (nums[i] > nums[j])
        cnt++;
    }
    ans.emplace_back(cnt);
    cnt = 0;
  }
  return ans;
}
// better one
vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans;
  vector<int> vec(nums);
  sort(nums.begin(), nums.end());
  map<int, int> mp;
  int m = 0, prev = -1;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] != prev)
    {
      mp[nums[i]] = i;
    }
    prev = nums[i];
  }
  for (int i = 0; i < n; i++)
  {
    ans.emplace_back(mp[vec[i]]);
  }
  return ans;
}
// counting sort
vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
  vector<int> cnt(101, 0);
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    cnt[nums[i]]++;
  }
  for (int i = 1; i < 101; i++)
  {
    cnt[i] += cnt[i - 1];
  }
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] == 0)
      ans.emplace_back(0);
    else
      ans.emplace_back(cnt[nums[i] - 1]);
  }
  return ans;
}