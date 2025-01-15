#include <bits/stdc++.h>
using namespace std;
//o(n+m)
class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    vector<int> ans;
    int l1 = 0, l2 = 0;
    while (l1 < m && l2 < n)
    {
      if (nums1[l1] < nums2[l2])
      {
        ans.emplace_back(nums1[l1]);
        l1++;
      }
      else
      {
        ans.emplace_back(nums2[l2]);
        l2++;
      }
    }
    while (l1 < m)
    {
      ans.emplace_back(nums1[l1]);
      l1++;
    }
    while (l2 < n)
    {
      ans.emplace_back(nums2[l2]);
      l2++;
    }
    nums1 = ans;
  }
};