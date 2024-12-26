#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k;
  cin>>n>>k;
  int rem = 240-k;
  int ans=0,i=1;
  while(rem >=(i*5)  && n){
    ans++;
    rem= rem-(ans*5);
    n--;
    i++;
  }
  cout<<ans<<endl;
  return 0;
}