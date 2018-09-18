
#include <stack>
#include <string>
#include <vector>

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

int longestValidParentheses(const char* s) {
  if (s == nullptr || s[0] == '\0') return 0;
  int current_level = s[0] == '(' ? 1 : -1;
  int current_length = current_level < 0 ? 0 : 1;
  int max_length = 0;
  int index = 1;
  while (s[index] != '\0') {
    if (current_length < 0) current_length = 0;
    current_length += s[index] == '(' ? 1 : -1;
    if (current_length == 0)
      if (max_length < current_length) max_length = current_length;
    ++index;
  }

  return max_length;
}

int main(void) {
  Solution sln;
  sln.longestValidParentheses("()");
  longestValidParentheses("(()");
  return 0;
}