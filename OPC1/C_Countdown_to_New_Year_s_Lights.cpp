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
    string s;
    cin>>s;
    int cnt=0;
    int ans=0;
    for(int i=0;i<s.length();i++){
      if(s[i]=='A' || s[i]=='E' || s[i]=='O' || s[i]=='I' || s[i]=='U' || s[i]=='Y'){
        ans=max(ans,cnt);
        cnt=0;
      }
      else{
        cnt++;
      }
    }
    ans=max(cnt,ans);
    cout<<ans+1<<"\n";
  }
  return 0;
}