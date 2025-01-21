#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MAX = 2e5+5;
ll MOD = 1000000007;
#define yes   cout << "yes\n";
#define no    cout << "no\n";
template<typename T> istream& operator>>(istream &in, vector<T> &a) {
    for (auto &e : a) cin >> e;
    return in;
}
ll mul(ll a, ll b) {
    return (a * b);
}
ll power(int x, unsigned int y) {
    long long int temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return mul(temp, temp);
    else
        return mul(x, mul(temp, temp));
}
ll min(ll a, ll b) {
    return (a <= b) ? a : b;
}
ll max(ll a, ll b) {
    return (a >= b) ? a : b;
}
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}
void printV(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
void printA(int* v, int size) {
    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
void solve() {
    // ll n, m, a, b, c, x, y, z, ct, mn, mx, ans;
    // ans = 0, mx = INT_MIN, mn = INT_MAX, ct = 0, c = 0;
    int n,p,m;
    cin>>n>>p>>m;
    vector<pair<int,int>> vec(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
      int x,y;
      cin>>x>>y;
      vec[i]={x,y};
      mp[x]=y;
    }
    // sort(vec.begin(),vec.end());
    long long left=0,right=0;
    for(int i=1;i<=m;i++){
      left+=mp[i+p];
      right+=mp[p-i];
    }
    cout<<max(left,right)<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }
    solve();
    return 0;
}