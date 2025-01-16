#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int n = height.size();
    int ans = 0;
    int mx = 0;
    int i = 0, j = n - 1;
    while (i < j)
    {
      ans = min(height[i], height[j]) * (j - i);
      mx = max(mx, ans);
      if (height[i] > height[j])
      {
        int man = height[j];
        j--;
        while (j > i && height[j] < man)
        {
          j--;
        }
      }
      else
      {
        int man = height[i];
        i++;
        while (i < j && height[i] < man)
        {
          i++;
        }
      }
    }
    return mx;
  }
};
// a shorter one
class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int n = height.size();
    int ans = 0;
    int mx = 0;
    int i = 0, j = n - 1;
    while (i < j)
    {
      ans = min(height[i], height[j]) * (j - i);
      mx = max(mx, ans);
      if (height[i] > height[j])
      {
        j--;
      }
      else
      {
        i++;
      }
    }
    return mx;
  }
};
//TC O(n)