#include<bits/stdc++.h>
using namespace std;

//using O(nlogn) and O(n) space
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n=arr.size();
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++){
            vec[i]=make_pair(arr[i],dep[i]);
        }
        sort(vec.begin(),vec.end());
        multiset<int> st;
        int ans=0;
        int plat=0;
        for(int i=0;i<n;i++){
            if(st.empty()){
                plat=1;
                ans=max(ans,plat);
                st.insert(vec[i].second);
            }
            else{
                while(!st.empty() && *st.begin() < vec[i].first){
                    plat--;
                    // ans=max(plat,ans);
                    st.erase(st.begin());
                }
                plat++;
                ans=max(plat,ans);
                st.insert(vec[i].second);
            }
            // cout<<ans<<"\n";
        }
        return ans;
    }
};

//optimal one without using extra space

class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i=1,j=0;
        int n=arr.size();
        int ans=1,plat=1;
        while(i<n && j<n){
            if(arr[i]<= dep[j]){
                plat++;
                i++;
            }
            else{
                plat--;
                j++;
            }
            ans=max(ans,plat);
        }
        return ans;
    }
};


