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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.length();i++){
      if(s[i]=='G'){
        ans++;
      }
      else{
        if(k){
          k--;
        }
        else{
          break;
        }
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}