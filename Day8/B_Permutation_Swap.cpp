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
    vector<int> vec(a,a+n);
    sort(vec.begin(),vec.end());
    int mn=0;
    for(int i=0;i<n;i++){
      vec[i]= abs(a[i]-vec[i]);
      mn= __gcd(mn,vec[i]);
    }
    cout<<mn<<"\n";
  }
  return 0;
}