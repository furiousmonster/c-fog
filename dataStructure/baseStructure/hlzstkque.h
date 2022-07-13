#ifndef HLZSTKQUE_H
#define HLZSTKQUE_H


#include <stack>
#include <vector>

using namespace std;


class monoStack {
private:
  stack<int> stk;



public:

  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n);
    stack<int> s;
    for (int i = 0; i < n; ++i) {
      while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
        int previousIndex = s.top();
        ans[previousIndex] = i - previousIndex;
        s.pop();
      }
      s.push(i);
    }
    return ans;
  }





};





#endif