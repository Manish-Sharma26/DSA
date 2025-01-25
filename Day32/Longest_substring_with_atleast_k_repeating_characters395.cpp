#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestSubstring(string s, int k)
  {
    map<char, int> mp;
    for (auto i : s)
    {
      mp[i]++;
    }
    int ans = 0;
    int n = s.length();
    int unique_char = mp.size();
    for (int curr_unique = 1; curr_unique <= unique_char; curr_unique++)
    {
      mp.clear();
      int i = 0, j = 0;
      int char_atleastk = 0, unique = 0;
      while (j < n)
      {
        if (unique <= curr_unique)
        {
          if (mp[s[j]] == 0)
          {
            unique++;
          }
          mp[s[j]]++;
          if (mp[s[j]] == k)
          {
            char_atleastk++;
          }
          j++;
        }
        else
        {
          if (mp[s[i]] == k)
          {
            char_atleastk--;
          }
          mp[s[i]]--;
          if (mp[s[i]] == 0)
          {
            unique--;
          }
          i++;
        }
        if (unique == curr_unique && unique == char_atleastk)
        {
          ans = max(j - i, ans);
        }
      }
    }
    return ans;
  }
};