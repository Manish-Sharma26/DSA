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
    ll sum =0;
    for(auto& i:a){
      cin>>i;
      sum+=abs(i);
    }
    int prev=INT_MAX;
    ll op=0;
    int i=0;
    while(i<n){
      if(a[i]<0){
        i++;
        while(a[i]<=0 && i<n){
          i++;
        }
        op++;
      }
      else{
        i++;
      }
    }
    cout<<sum<<" "<<op<<"\n";
  }
  return 0;
}