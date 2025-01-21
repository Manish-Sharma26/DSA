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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vec(n,vector<int>(3,0) );
    for(int i=0;i<n;i++){
      for(int j=0;j<3;j++){
        cin>>vec[i][j];
      }
    }
    bool flag=0;
    int ans = m;
    int left=m,right=m;
    int time=0;
    for(int i=0;i<n;i++){
      left= left-(vec[i][0]-time);
      right= (vec[i][0]-time)+right;
      // cout<<left<<' '<<right<<"\n";

      if(right < vec[i][1] || left > vec[i][2]){
        flag=1;
        break;
      }
      left=max(left,vec[i][1]);
      right=min(right,vec[i][2]);
      time=vec[i][0];
      // cout<<left<<' '<<right<<"\n";
    }
    if(flag)
    cout<<"NO\n";
    else
    cout<<"YES\n";
    // for(auto i:vec){
    //   for(auto j:i){
    //     cout<<j<<" ";
    //   }cout<<"\n";
    // }
  }
  return 0;
}