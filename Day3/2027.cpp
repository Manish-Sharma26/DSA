#include <bits/stdc++.h>
using namespace std;
int minimumMoves(string s)
{
  int n = s.length();
  int i = 0, cnt = 0;
  while (i < n)
  {
    if (s[i] == 'X')
    {
      i += 3;
      cnt++;
    }
    else
    {
      i++;
    }
  }
  return cnt;
}