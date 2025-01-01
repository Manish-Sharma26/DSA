#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canJump(vector<int> &nums)
  {
    int n = nums.size();
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
      if (i > mx)
        return false;
      mx = max(mx, i + nums[i]);
      if (mx >= n - 1)
        return true;
    }
    return true;
  }
};
// another one
class Solution
{
public:
  bool canJump(vector<int> &nums)
  {
    int goal = nums.size() - 1;
    for (int i = goal - 1; i >= 0; i--)
    {
      if (i + nums[i] >= goal)
      {
        goal = i;
      }
    }
    return (goal == 0);
  }
};