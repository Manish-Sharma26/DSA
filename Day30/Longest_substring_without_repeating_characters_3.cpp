#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int n = s.length();
    if (n == 0 || n == 1)
      return n;
    int i = 0, j = 0;
    int mx = -1;
    // map<char,int> mp;
    vector<int> store(128, -1);
    while (i < n && j < n)
    {
      int ind = (int)s[j];
      if (store[ind] != -1)
      {
        mx = max(mx, (j - i));
        // cout<<mx<<"\n";
        i = max(i, store[ind] + 1);
        // mp[s[j]]=j;
        store[ind] = j;
      }
      else
      {
        // mp[s[j]]=j;
        store[ind] = j;
      }
      j++;
    }
    mx = max(mx, (j - i));
    return mx;
  }
};

// another one 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0 || n == 1)
            return n;
        int i = 0, j = 0;
        int mx = -1;
        vector<int> store(256, -1);
        while (i < n && j < n) {
            int idx = (int)s[j] ;
            i = max(i, store[idx] + 1);
            store[idx] = j;
            mx = max(mx, j + 1 - i);
            j++;
        }
        // mx = max(mx, (j - i));
        return mx;
    }
};