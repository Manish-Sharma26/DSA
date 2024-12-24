#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  string s;
  cin>>s;
  if(n<26){
    cout<<"NO\n";
  }
  else{
    int arr[26]={0};
    for(int i=0;i<s.length();i++){
      int ind = tolower(s[i]) - 97;
      arr[ind]++;
    }
    bool flag =0;
    for(int i=0;i<26;i++){
      if(arr[i]==0){
        flag=1;
        break;
      }
    }
    if(flag)
    cout<<"NO\n";
    else
    cout<<"YES\n";
  }
  return 0;
}