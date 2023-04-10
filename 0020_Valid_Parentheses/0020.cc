
#include <assert.h>

#include <stack>
#include <string>

using std::stack;
using std::string;

class Solution {
 public:
  bool isValid(const string s) {
    stack<char> stk;
    for (const char ch : s)
      switch (ch) {
        case '(':
        case '{':
        case '[':
          stk.push(ch);
          break;
        case ')':
          if (stk.empty() || stk.top() != '(') return false;
          stk.pop();
          break;
        case '}':
          if (stk.empty() || stk.top() != '{') return false;
          stk.pop();
          break;
        case ']':
          if (stk.empty() || stk.top() != '[') return false;
          stk.pop();
          break;
        default:
          abort();
          break;
      }
    return stk.empty();
  }
};

int main(void) {
  Solution sln;
  assert(sln.isValid("()"));
  return 0;
}
