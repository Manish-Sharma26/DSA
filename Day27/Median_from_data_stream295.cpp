#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
  vector<int> man;
  MedianFinder()
  {
    man.clear();
  }

  void addNum(int num)
  {
    int n = man.size();
    if (n == 0)
    {
      man.push_back(num);
    }
    else
    {
      auto ind = upper_bound(man.begin(), man.end(), num);
      man.insert(ind, num);
    }
  }

  double findMedian()
  {
    // for(auto i:man){
    //     cout<<i<<" ";
    // }cout<<"\n";
    int n = man.size();
    if (n % 2 == 0)
    {
      return (man[n / 2] + man[(n / 2) - 1]) / 2.0;
    }
    else
    {
      return man[n / 2];
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */