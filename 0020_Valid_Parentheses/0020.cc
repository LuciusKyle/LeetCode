
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include<assert.h>

using std::stack;
using std::string;

class Solution {
 public:
  Solution() : parentheses{'(', '{', '['}, reverse_parentheses{')', '}', ']'} {
    parenthesis_pairs.insert({')', '('});
    parenthesis_pairs.insert({'}', '{'});
    parenthesis_pairs.insert({']', '['});
  }

  bool isValid(string s) {
    std::stack<char> parentheses_stack;
    for (const char ch : s) {
      if (parentheses.count(ch) > 0) {
        parentheses_stack.push(ch);
        continue;
      }
      if (reverse_parentheses.count(ch) > 0) {
        if (parentheses_stack.empty()) return false;
        if (parentheses_stack.top() != parenthesis_pairs.at(ch)) return false;
        parentheses_stack.pop();
      }
    }
    if (parentheses_stack.empty())
      return true;
    else
      return false;
  }

 private:
  const std::unordered_set<char> parentheses;
  const std::unordered_set<char> reverse_parentheses;
  std::unordered_map<char, char> parenthesis_pairs;
};

int main(void) {
  Solution sln;
  assert(sln.isValid("()"));
  return 0;
}
