#include <bits/stdc++.h>
using namespace std;

int numberOfBeams(vector<string> &bank)
{
  int m = bank.size();
  int n = bank[0].size();
  vector<int> vec(m, 0);
  int ans = 0;
  for (int i = 0; i < m; i++)
  {
    ans = 0;
    for (int j = 0; j < n; j++)
    {
      if (bank[i][j] == '1')
        ans++;
    }
    vec[i] = ans;
  }

  ans = 0;
  int prev = vec[0];
  for (int i = 1; i < m; i++)
  {
    if (vec[i] != 0)
    {
      ans += prev * vec[i];
      prev = vec[i];
      cout << ans << endl;
    }
  }
  return ans;
}

// optimal one
int numberOfBeams(vector<string> &bank)
{
  int prev = 0, ans = 0;
  for (string s : bank)
  {
    int cnt = 0;
    for (auto c : s)
    {
      if (c == '1')
        cnt++;
    }
    if (cnt != 0)
    {
      ans += (prev * cnt);
      prev = cnt;
    }
  }
  return ans;
}