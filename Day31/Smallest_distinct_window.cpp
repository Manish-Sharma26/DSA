#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int compute(vector<int> nums, int k)
  {
    // if(k<0){}
    int i = 0, j = 0, cnt = 0, ans = 0;
    while (j < nums.size())
    {
      cnt += nums[j] % 2;
      while (cnt > k)
      {
        cnt -= nums[i] % 2;
        i++;
      }
      ans += (j - i + 1);
      j++;
    }
    return ans;
  }
  int numberOfSubarrays(vector<int> &nums, int k)
  {
    return compute(nums, k) - compute(nums, k - 1);
  }
};
