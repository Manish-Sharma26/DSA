#include <bits/stdc++.h>
using namespace std;
// dutch flag algorithm
void sortColors(vector<int> &arr)
{
  int n = arr.size();
  int low = 0, mid = 0, high = n - 1;
  while (mid <= high)
  {
    if (arr[mid] == 0)
    {
      swap(arr[low++], arr[mid++]);
    }
    else if (arr[mid] == 1)
    {
      mid++;
    }
    else
    {
      swap(arr[mid], arr[high--]);
    }
  }
}
// counting approach
void sortColors(vector<int> &nums)
{
  int n = nums.size();
  int c0 = 0, c2 = 0, c1 = 0;
  ;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] == 0)
      c0++;
    else if (nums[i] == 1)
      c1++;
    else
      c2++;
  }
  // cout<<c1<<" "<<c1<<" "<<c2<<endl;
  for (int i = 0; i < n; i++)
  {
    if (i < c0)
    {
      nums[i] = 0;
    }
    else if (i >= c0 && i < c1 + c0)
    {
      nums[i] = 1;
    }
    else
    {
      nums[i] = 2;
    }
  }
}