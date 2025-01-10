#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<int> a,int ind){
  vector<int> vec;
  for(int i=0;i<a.size();i++){
    if(i==ind){}
    else{
      vec.push_back(a[i]);
    }
  }
  int prev=1;
  for(int i=0;i<vec.size()-1;i++){
    int temp =__gcd(vec[i],vec[i+1]);
    if(prev > temp)
    return false;
    prev=temp;
  }
  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto& i:a){
      cin>>i;
    }
    int prev=1,ind =0;
    for(int i=0;i<n-1;i++){
      int temp = __gcd(a[i],a[i+1]);
      if(prev > temp){
        ind = i;
        break;
      }
      prev = temp;
    }

    if(check(a,ind) || check(a,ind+1)|| check(a,ind-1))
    cout<<"YES\n";
    else
    cout<<"NO\n";
    // vector<int> g;
    // for(int i=1;i<n;i++){
    //   g.push_back(__gcd(a[i-1],a[i]));
    // }
    // int cnt=0;
    // for(int i=1;i<g.size();i++){
    //   if(g[i]<g[i-1]){
        
    //   }
    // }
    
  }
  return 0;
}
