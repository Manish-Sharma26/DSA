#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
  {
    int n = nums.size();
    int i = 0, j = 0;
    int cnt = 0;
    int mx = -1;
    int man = -1;
    while (i < n && j < n)
    {
      // cout<<i<<" "<<j<<" "<<cnt<<"\n";
      mx = max(mx, nums[j]);
      if (mx >= left && mx <= right)
      {
        cnt += (j - i) + 1;
        if (!(nums[j] >= left && nums[j] <= right))
        {
          cnt -= (j - man);
        }
        else
        {
          man = j;
        }
        j++;
      }
      else if (mx > right)
      {
        j++;
        i = j;
        mx = -1;
      }
      else
      {
        j++;
      }
    }
    return cnt;
  }
};
// a shorter one
class Solution
{
public:
  int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
  {
    int i = 0, j = 0;
    int valid = 0;
    int ans = 0;
    for (i = 0; i < nums.size(); i++)
    {
      if (nums[i] >= left && nums[i] <= right)
      {
        valid = i - j + 1;
        ans += valid;
      }
      else if (nums[i] < left)
      {
        ans += valid;
      }
      else
      {
        valid = 0;
        j = i + 1;
      }
    }
    return ans;
  }
};