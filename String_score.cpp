// 3110. Score of a String
/*
You are given a string s. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.
Return the score of s.
*/
#include <iostream>
using namespace std;

int scoreOfString(string s)
{
  int ans = 0;
  for (int i = 1; i < s.length(); i++)
  {
    ans += abs(s[i - 1] - s[i]);
  }
  return ans;
}
