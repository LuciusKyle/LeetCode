
#include <stack>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> answer(temperatures.size(), 0);
    std::stack<int> dec_mono_stk;
    for (int i = 0; i < temperatures.size(); ++i) {
      while (!dec_mono_stk.empty() && temperatures[dec_mono_stk.top()] < temperatures[i]) {
        answer[dec_mono_stk.top()] = i - dec_mono_stk.top();
        dec_mono_stk.pop();
      }
      dec_mono_stk.push(i);
    }
    return answer;
  }
};
