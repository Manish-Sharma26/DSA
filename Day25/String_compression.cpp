#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int compress(vector<char> &chars)
  {
    int n = chars.size();
    if (n == 1)
    {
      return 1;
    }
    char ans = chars[n - 2];
    int cnt = 1, i, j;
    for (i = 0, j = 0; j < n - 1; j++)
    {
      if (chars[j] == chars[j + 1])
      {
        cnt++;
      }
      else
      {
        if (cnt == 1)
        {
          chars[i] = chars[j];
          i++;
        }
        else
        {
          chars[i] = chars[j];
          i++;
          vector<int> vec;
          while (cnt)
          {
            vec.push_back(cnt % 10);
            cnt /= 10;
          }
          for (int x = vec.size() - 1; x >= 0; x--)
          {
            chars[i] = vec[x] + 48;
            i++;
          }
        }
        cnt = 1;
      }
    }
    if (ans == chars[n - 1])
    {
      chars[i] = chars[j];
      i++;
      vector<int> vec;
      while (cnt)
      {
        vec.push_back(cnt % 10);
        cnt /= 10;
      }
      for (int x = vec.size() - 1; x >= 0; x--)
      {
        chars[i] = vec[x] + 48;
        i++;
      }
      i--;
    }
    else
    {
      chars[i] = chars[n - 1];
    }
    return i + 1;
  }
};

// a smaller one
class Solution
{
public:
  int compress(vector<char> &chars)
  {
    int n = chars.size();
    int i, j;
    for (i = 0, j = 0; j < n; j++)
    {
      char ch = chars[j];
      int cnt = 0;
      while (j < n && chars[j] == ch)
      {
        j++;
        cnt++;
      }
      if (cnt == 1)
      {
        chars[i++] = ch;
      }
      else
      {
        chars[i++] = ch;
        string str = to_string(cnt);
        for (char val : str)
        {
          chars[i++] = val;
        }
      }
      j--;
    }
    return i;
  }
};