// Your task is to calculate the number of trailing zeros in the factorial n!.
// For example, 20!=2432902008176640000 and it has 4 trailing zeros.

#include<iostream>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int cnt=0;
  while(n>=5){
    n/=5;
    cnt+=n;
  }
  cout<<cnt<<"\n";
  return 0;
}