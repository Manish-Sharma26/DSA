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
    // ll n;
    // cin>>n;
    // ll ans1=0,ans2=0;
    // if(n%4==0){
    //   ans1=n/4;
    // }
    // if(n%6==0 ){
    //   ans2=n/6;
    // }
    // if(n%6==4 ){
    //   ans2=n/6 +1;
    // }
    // if(n%4==2){
    //   ans1=n/4;
    // }
    // if(n%6==2){
    //   ans2=n/6+1;
    // }
    // if(ans1 && ans2){
    //   cout<<min(ans1,ans2)<<" "<<max(ans1,ans2)<<"\n";
    // }

    // else if(ans1){
    //   cout<<ans1<<" "<<ans1<<"\n";
    // }
    // else if(ans2){
    //   cout<<ans2<<" "<<ans2<<"\n";
    // }
    // else{
    //   cout<<-1<<"\n";
    // }

    ll n;
    cin>>n;

    if(n%2==1){
      cout<<-1<<"\n";
    }
    else if(n<4){
      cout<<-1<<"\n";
    }
    else{
      ll ans=0;
      ans=n/4;
      ll ans1=0;
      ans1=n/6;
      if(n%6!=0){
        ans1=ans1+1ll;
      }
      cout<<min(ans,ans1)<<" "<<max(ans,ans1)<<"\n";
    }
  }
  return 0;
}