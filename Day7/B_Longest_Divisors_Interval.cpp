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
    ll n;
    cin>>n;
    int i=2;
    while(1){
      if(n%i!=0){
        break;
      }
      i++;
    }
    cout<<i-1<<"\n";
  }
  return 0;
}