#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string reduce(string word)
{
  string ans = "";
  for (int i = 0; i < word.length(); i++)
  {
    if (word[i] == word[i + 1])
    {
      continue;
    }
    ans += word[i];
  }
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int n;
  cin >> n;
  string arr[n];
  for (auto &i : arr)
  {
    cin >> i;
  }
  
  string ans = "";
  int cnt = 1;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == s[i + 1])
    {
      cnt++;
      continue;
    }
    ans += s[i];
    cnt = 1;
  }
  string s1 = ans;

  map<pair<char, int>, int> mp;
  int ind = 0;
  mp[{s[0], ind}]++;
  for (int i = 1; i < s.length(); i++)
  {
    if (s[i] != s[i - 1])
      ind++;
    mp[{s[i], ind}]++;
  }
 
  int man = 0;
  for (int i = 0; i < n; i++)
  {
    if (reduce(arr[i]) == s1)
    {
      map<pair<char, int>, int> mp1;
      // for(auto j:arr[i]){
      //   mp1[j]++;
      // }
      auto j = arr[i];
      int ind = 0;
      mp1[{j[0], ind}]++;
      for (int i = 1; i < j.length(); i++)
      {
        if (j[i] != j[i - 1])
          ind++;
        mp1[{j[i], ind}]++;
      }
      // cout<<"inner\n";
      // for (auto i : mp1)
      // {
      //   cout << i.first.first << " " << i.first.second << " " << i.second << "\n";
      // }
      bool flag = 1;
      // for(auto i:mp1){
      //   cout<<i.first<<" "<<i.second<<"\n";
      // }
      for (auto m1 = mp.begin(), m2 = mp1.begin(); m1 != mp.end() || m2 != mp1.end(); m1++, m2++)
      {
        int r = (m1->second - m2->second);
        if (r == 0 || (r > 0 && m1->second >2))
        {
        }
        else
        {
          flag = 0;
          break;
        }
      }
      if (flag)
        man++;
      // cout<<man<<"\n";
    }
  }
  cout << man << "\n";
  return 0;
}

//another one
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    int sz1= s.size();
    
    int n;
    cin>>n;
    int count =0;
    for(int i=0;i<n;i++){
        int p1 = 0, p2 =0;
        string str;
        cin>>str;
        int sz2 = str.size();
        if(sz1 < sz2){
            continue;
        }
        bool found = true;
        while(p1<sz1 && p2<sz2){
            int c1 =1, c2=1;
            while(p1<sz1-1 && s[p1]== s[p1+1]){
                p1++;
                c1++;
            }
            while(p2<sz2-1 && str[p2]==str[p2+1]){
                p2++;
                c2++;
            }
            if(s[p1] != str[p2] || c1 != c2 && (c1<3 || c2>c1)){
                found = false;
                break;
            }
            p1++;
            p2++;
        }
        if(found && s[p1]==str[p2]) count++;
    }
    cout<< count<<'\n';
    return 0;
}

