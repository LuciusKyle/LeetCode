
#include <assert.h>
#include <string>

using std::string;

class Solution {
 public:
  string addStrings(const string &num0, const string num1) {
    string reverse_rtn;
    int carry = 0;
    auto iter0 = num0.crbegin(), iter1 = num1.crbegin();
    while (iter0 != num0.crend() || iter1 != num1.crend()) {
      const int num = (iter0 == num0.crend() ? 0 : *iter0 - '0') + (iter1 == num1.crend() ? 0 : *iter1 - '0') + carry;
      reverse_rtn.push_back(num % 10 + '0');
      carry = num / 10;
      if (iter0 != num0.crend()) ++iter0;
      if (iter1 != num1.crend()) ++iter1;
    }
    if (carry) reverse_rtn.push_back(carry % 10 + '0');
    return {reverse_rtn.crbegin(), reverse_rtn.crend()};
  }
};

int main(void) {
  Solution sln;
  assert("579" == sln.addStrings("123", "456"));
  return 0;
}
