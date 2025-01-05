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
    int l,b,h,s;
    cin>>l>>b>>h>>s;
    int v1=l*b*h;
    int v2=s*s*s;
    if(v1>v2){
      cout<<"CUBE\n";
    }
    else if(v2>v1){
      cout<<"CUBOID\n";
    }
    else{
      cout<<"EQUAL\n";
    }
  }
  return 0;
}