#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> minOperations(string boxes)
  {
    int n = boxes.size();
    int ans = 0;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (boxes[j] == '1')
        {
          ans += abs(j - i);
        }
      }
      vec.push_back(ans);
      ans = 0;
    }
    return vec;
  }
};