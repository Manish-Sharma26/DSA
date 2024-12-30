#include <bits/stdc++.h>
using namespace std;

// using division
class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    long long prod = 1;
    int n = nums.size();
    vector<int> ans;
    int cnt = 0, ind = 0;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == 0)
      {
        cnt++;
        ind = i;
      }
      else
      {
        prod *= nums[i];
      }
    }
    vector<int> temp(n, 0);
    ans = temp;
    if (cnt > 1)
    {
    }
    else if (cnt == 1)
    {
      ans[ind] = prod;
    }
    else
    {
      for (int i = 0; i < nums.size(); i++)
      {
        if (prod != 0)
        {
          ans[i] = prod / nums[i];
        }
      }
    }
    return ans;
  }
};

// using prefix and suffix
class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> pref(n, 1);
    vector<int> suf(n, 1);
    vector<int> ans(n, 1);
    for (int i = 1; i < n; i++)
    {
      pref[i] = nums[i - 1] * pref[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
      suf[i] *= nums[i + 1] * suf[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
      ans[i] = pref[i] * suf[i];
    }
    return ans;
  }
};

// optimal one O(n) Time and O(1) space;
class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> ans(n, 1);
    for (int i = 1; i < n; i++)
    {
      ans[i] = nums[i - 1] * ans[i - 1];
    }
    int output = 1;
    for (int i = n - 2; i >= 0; i--)
    {
      output *= nums[i + 1];
      ans[i] *= output;
    }
    return ans;
  }
};
