
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    rtn.clear();
    string str;
    str.reserve(2 * n + 1);
    push_back_parenthesis(str, 0,0,n);
    return rtn;
  }

 private:
  vector<string> rtn;
  void push_back_parenthesis(string &str, const size_t parenthesis_count,
                             const size_t reverse_parenthesis_count,
                             const size_t n) {
    if (reverse_parenthesis_count == n) {
      rtn.push_back(str);
      return;
    }

    if(parenthesis_count<n){
      str.push_back('(');
      push_back_parenthesis(str, parenthesis_count + 1,
                            reverse_parenthesis_count, n);
      str.pop_back();
    }
    if(reverse_parenthesis_count < n && reverse_parenthesis_count < parenthesis_count){
      str.push_back(')');
      push_back_parenthesis(str, parenthesis_count,
                            reverse_parenthesis_count + 1, n);
      str.pop_back();
    }
  }
};


int main(void)
{
  Solution sln;
  auto rtn = sln.generateParenthesis(2);

  return 0;
}