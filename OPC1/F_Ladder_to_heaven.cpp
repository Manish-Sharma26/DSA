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
    for(auto& i:a){
      cin>>i;
    }
    vector<int> g;
    for(int i=1;i<n;i++){
      g.push_back(__gcd(a[i-1],a[i]));
    }
    int cnt=0;
    for(int i=1;i<g.size();i++){
      if(g[i]<g[i-1]){
        cnt++;
      }
    }
  }
  return 0;
}