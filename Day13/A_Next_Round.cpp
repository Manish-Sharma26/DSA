#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k;
  cin>>n>>k;
  int a[n];
  for(auto& i:a){
    cin>>i;
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(a[i]==0)
    continue;
    if(a[i]>=a[k-1])
    ans++;
  }
  cout<<ans<<"\n";
  return 0;
}