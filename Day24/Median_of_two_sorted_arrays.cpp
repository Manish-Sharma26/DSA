#include <bits/stdc++.h>
using namespace std;

// first one O(m+n) with space O(n)
class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    int m = nums1.size();
    int n = nums2.size();
    vector<int> ans;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
      if (nums1[i] < nums2[j])
      {
        ans.emplace_back(nums1[i]);
        i++;
      }
      else
      {
        ans.emplace_back(nums2[j]);
        j++;
      }
    }
    while (i < m)
    {
      ans.emplace_back(nums1[i]);
      i++;
    }
    while (j < n)
    {
      ans.emplace_back(nums2[j]);
      j++;
    }
    double median;
    if ((m + n) % 2 == 0)
    {
      int index = (m + n) / 2;
      median = ((double)ans[index] + (double)ans[index - 1]) / 2.0;
    }
    else
    {
      median = (double)ans[(m + n) / 2];
    }
    return median;
  }
};
// better one without space
class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    // modification inseatd of storing just find mid elements;
    int m = nums1.size();
    int n = nums2.size();
    int ind2 = (m + n) / 2;
    int ind1 = ind2 - 1;
    int ans1 = 0, ans2 = 0;
    int cnt = 0;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
      if (nums1[i] < nums2[j])
      {
        if (cnt == ind1)
          ans1 = nums1[i];
        if (cnt == ind2)
          ans2 = nums1[i];
        cnt++;
        i++;
      }
      else
      {
        if (cnt == ind1)
          ans1 = nums2[j];
        if (cnt == ind2)
          ans2 = nums2[j];
        j++;
        cnt++;
      }
    }
    while (i < m)
    {
      if (cnt == ind1)
        ans1 = nums1[i];
      if (cnt == ind2)
        ans2 = nums1[i];
      i++;
      cnt++;
    }
    while (j < n)
    {
      if (cnt == ind1)
        ans1 = nums2[j];
      if (cnt == ind2)
        ans2 = nums2[j];
      j++;
      cnt++;
    }
    double median;
    if ((m + n) % 2 == 0)
    {
      median = (ans2 + ans1) / 2.0;
    }
    else
    {
      median = (double)ans2;
    }
    return median;
  }
};
// optimal
class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    int n1 = nums1.size();
    int n2 = nums2.size();
    if (n1 > n2)
    {
      return findMedianSortedArrays(nums2, nums1);
    }
    int left = (n1 + n2 + 1) / 2;
    int low = 0, high = n1;
    while (low <= high)
    {
      int mid1 = low + (high - low) / 2;
      int mid2 = left - mid1;
      int l1 = INT_MIN, l2 = INT_MIN;
      int r1 = INT_MAX, r2 = INT_MAX;
      if (mid1 < n1)
        r1 = nums1[mid1];
      if (mid2 < n2)
        r2 = nums2[mid2];
      if (mid1 - 1 >= 0)
        l1 = nums1[mid1 - 1];
      if (mid2 - 1 >= 0)
        l2 = nums2[mid2 - 1];
      if (l1 <= r2 && l2 <= r1)
      {
        if ((n1 + n2) % 2 == 1)
          return max(l1, l2);
        return ((double)max(l1, l2) + (double)min(r1, r2)) / 2.0;
      }
      else if (l1 > r2)
        high = mid1 - 1;
      else
        low = mid1 + 1;
    }
    return 0;
  }
};