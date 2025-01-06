#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
  int low = 0, high = nums.size() - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (nums[mid] == target)
      return mid;
    else if (nums[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

// recursive one
int binary(vector<int> &nums, int low, int high, int x)
{
  if (low > high)
    return -1;
  int mid = low + (high - low) / 2;
  if (nums[mid] == x)
  {
    return mid;
  }
  else if (nums[mid] > x)
  {
    return binary(nums, low, mid - 1, x);
  }
  else
  {
    return binary(nums, mid + 1, high, x);
  }
}
int search(vector<int> &nums, int target)
{
  return binary(nums, 0, nums.size() - 1, target);
}
