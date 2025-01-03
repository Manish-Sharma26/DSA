#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int a[n];
    ll one=0,zero=0;
    for(auto& i:a){
      cin>>i;
      if(i==0)
      zero++;
      else if(i==1)
      one++;
    }
    ll ans=one;
    for(ll i=0;i<zero;i++){
      ans*= 2;
    }
    cout<<ans<<"\n";
  }
  return 0;
}