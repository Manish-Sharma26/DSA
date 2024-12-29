#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isprime(int n)
{
  if (n == 1)
    return false;
  if (n == 2 || n == 3)
    return true;
  if (n % 2 == 0)
    return false;
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      return false;
    }
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  if (n < 6)
  {
    cout << 0;
    return 0;
  }
  int ans = 0;
  int divisor = 0;
  for (int i = 6; i <= n; i++)
  {
    int temp = i;
    int div = 0;
    for (int j = 2; j <= temp; j++)
    {
      if (isprime(j))
      {
        if (temp % j == 0)
          div++;
        while (temp % j == 0)
          temp /= j;
      }
    }
    if (div == 2)
      ans++;
  }
  cout << ans << "\n";
  return 0;
}