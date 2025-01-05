#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cntA=0,cntAN=0,cntANI=0,cntANIL=0;
    for(auto i:s){
      if(i=='A')
      cntA=(cntA+1)%MOD;
      else if(i=='N')
      cntAN=(cntAN+cntA)%MOD;
      else if(i=='I')
      cntANI=(cntANI+cntAN)%MOD;
      else if(i=='L')
      cntANIL=(cntANIL+cntANI)%MOD;
    }
    cout<<cntANIL<<"\n";
  }
  return 0;
}