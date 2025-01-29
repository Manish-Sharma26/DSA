#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestOnes(vector<int> &s, int k)
  {
    int n = s.size();

    // vector<int> s(n);
    // for (int i=0;i<n;i++ )
    //     cin >> s[i];

    int i = 0, j = 0;
    int cnt = 0;
    int ans = 0;
    while (j < n)
    {

      cnt += (s[j] == 0);
      j++;

      if (cnt <= k)
      {
        ans = max(ans, j - i);
      }
      else
      {
        cnt -= (s[i] == 0);
        i++;
      }
    }
    return ans;
  }
};
// another one
class Solution
{
public:
  int longestOnes(vector<int> &nums, int k)
  {
    int n = nums.size();
    int i = 0, j = 0;
    int cnt = 0;
    int ans = 0;
    int store = k;
    while (i < n && j < n)
    {
      if (nums[j] == 1)
      {
        j++;
      }
      else if (nums[j] == 0 && k)
      {
        j++;
        k--;
      }
      else
      {
        cnt = (j - i);
        // cout<<cnt<<"\n";
        ans = max(cnt, ans);
        if (nums[i] == 0)
        {
          k++;
        }
        i++;
      }
    }
    cnt = j - i;
    ans = max(cnt, ans);

    return ans;
  }
};