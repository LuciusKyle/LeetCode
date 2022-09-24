
#include <stack>
#include <string>

using std::string;

class Solution {
 public:
  string removeDuplicates(string s, int k) {
    std::stack<std::pair<char, int>> str_stk;
    for (const char ch : s) {
      if (str_stk.empty() || str_stk.top().first != ch)
        str_stk.push({ch, 1});
      else
        ++str_stk.top().second;
      if (k == str_stk.top().second) str_stk.pop();
    }
    s.clear();  // s is reversed answer.
    while (!str_stk.empty()) {
      for (int i = 0; i < str_stk.top().second; ++i)
        s.push_back(str_stk.top().first);
      str_stk.pop();
    }
    return {s.crbegin(), s.crend()};
  }
};