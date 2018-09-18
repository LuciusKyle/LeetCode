
#include <stack>
#include <string>
#include <vector>
#include<assert.h>

using std::stack;
using std::string;
using std::vector;

class Solution {
 public:
  int longestValidParentheses(string s) {
    if (s.empty()) return 0;
    const int len = s.size();
    int max_length = 0;
    stack<int> parenthesis_index;
    parenthesis_index.push(0);
    for (int i = 1; i <= len; ++i) {
      if (s[i - 1] == ')')
        if (parenthesis_index.top() > 0) {
          parenthesis_index.pop();
          int length = i - abs(parenthesis_index.top());
          if (max_length < length) max_length = length;
        } else
          parenthesis_index.push(-1 * i);
      else
        parenthesis_index.push(i);
    }
    return max_length;
  }
};

int main(void) {
  Solution sln;
  int rtn = sln.longestValidParentheses("()");
  assert(rtn == 2);
  return 0;
}