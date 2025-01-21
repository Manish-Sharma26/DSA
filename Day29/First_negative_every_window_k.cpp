#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
  vector<int> FirstNegativeInteger(vector<int> &arr, int k)
  {
    // write code here
    int n = arr.size();
    queue<int> q;
    for (int i = 0; i < k; i++)
    {
      if (arr[i] < 0)
        q.push(arr[i]);
    }
    vector<int> ans;
    if (q.empty())
    {
      ans.push_back(0);
    }
    else
    {
      ans.push_back(q.front());
    }
    int i = 0, j = k;
    while (j < n)
    {
      if (!q.empty() && q.front() == arr[i])
        q.pop();
      if (arr[j] < 0)
      {
        q.push(arr[j]);
      }
      if (q.empty())
      {
        ans.push_back(0);
      }
      else
      {
        ans.push_back(q.front());
      }
      i++;
      j++;
    }
    return ans;
  }
};
