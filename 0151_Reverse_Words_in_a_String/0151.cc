
#include <stack>
#include <string>

using std::stack;
using std::string;

class Solution {
 public:
  void reverseWords(string &s) {
    string buf;
    stack<string> stk;
    buf.reserve(s.size());
    for (const char ch : s)
      if (ch == ' ') {
        if (!buf.empty()) stk.push(buf);
        buf.clear();
      } else
        buf.push_back(ch);

    s = buf.empty() ? "" : (buf + " ");
    while (!stk.empty()) {
      s.append(stk.top() + " ");
      stk.pop();
    }
    s.erase(s.cend() - 1);
  }
};

int main(void) {
  Solution sln;
  string test_sample("the sky is blue");
  sln.reverseWords(test_sample);

  test_sample = "abc";
  sln.reverseWords(test_sample);

  test_sample = "abc def";
  sln.reverseWords(test_sample);

  test_sample = " ";
  sln.reverseWords(test_sample);

  test_sample = "a ";
  sln.reverseWords(test_sample);
  return 0;
}
