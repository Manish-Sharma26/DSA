#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string reverseWords(string s)
  {
    int n = s.size();
    string ans = "";
    stack<string> st;
    for (int i = 0; i < n; i++)
    {
      if (s[i] != 32)
      {
        ans += s[i];
      }
      else
      {
        if (ans != "")
        {
          st.push(ans);
          ans = "";
        }
      }
    }
    if (s[n - 1] != 32)
      st.push(ans);
    ans = "";
    while (st.size() > 1)
    {
      ans += st.top();
      ans += " ";
      st.pop();
    }
    ans += st.top();
    return ans;
  }
};

// optimal one using O(1) space
class Solution
{
public:
  string reverseWords(string s)
  {
    reverse(s.begin(), s.end());
    int left = 0, right = 0;
    int i = 0;
    int n = s.length();
    while (i < n)
    {
      while (i < n && s[i] == 32)
        i++;
      if (i == n)
        break;
      while (i < n && s[i] != 32)
      {
        s[right++] = s[i++];
      }
      reverse(s.begin() + left, s.begin() + right);
      s[right++] = ' ';
      left = right;
    }
    s.resize(right - 1);
    return s;
  }
};