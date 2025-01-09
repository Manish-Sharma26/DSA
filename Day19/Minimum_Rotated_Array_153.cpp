#include <bits/stdc++.h>
using namespace std;
// Based on left and right sorted potion
int findMin(vector<int> &nums)
{
  int l = 0, h = nums.size() - 1;
  int ans = INT_MAX;
  while (l <= h)
  {
    if (nums[l] <= nums[h])
    {
      ans = min(ans, nums[l]);
      break;
    }
    else
    {
      int mid = l + (h - l) / 2;
      if (nums[l] <= nums[mid])
      {
        ans = min(ans, nums[l]);
        l = mid + 1;
      }
      else
      {
        // cout<<nums[mid]<<"\n";
        ans = min(ans, nums[mid]);
        h = mid - 1;
      }
    }
  }
  return ans;
}

// another one based on mid and high
int findMin(vector<int> &nums)
{
  int low = 0, high = nums.size() - 1;
  while (low < high)
  {
    int mid = low + (high - low) / 2;
    if (nums[low] < nums[high])
    {
      return nums[low];
    }
    if (nums[mid] <= nums[high])
    {
      high = mid;
    }
    else
    {
      low = mid + 1;
    }
  }
  return nums[low];
}

// another version smaller one
int findMin(vector<int> &nums)
{
  int low = 0, high = nums.size() - 1;
  while (low < high)
  {
    int mid = low + (high - low) / 2;
    if (nums[mid] <= nums[high])
    {
      high = mid;
    }
    else
    {
      low = mid + 1;
    }
  }
  return nums[low];
}