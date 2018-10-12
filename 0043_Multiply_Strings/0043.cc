
#include<string>
#include<array>

using std::string;
using std::array;

// constexpr array<char, 10> int_to_char{}

class Solution {
 public:
  string multiply(string num0, string num1) {
    if (num0.size() < num1.size()) {
      std::swap(num0, num1);
    }
    if (num0[0] == '0' || num1[0] == '0') {
      return "0";
    }
    string rtn;
    for (size_t i = 0; i < num1.size(); ++i) {
      rtn = add(rtn, multiply(num0, num1[num1.size() - 1 - i] - '0') + string(i, '0'));
    }
    return rtn;
  }

 private:
  string multiply(const string num0, const int num1) {
    string reverse_rtn;
    int carry = 0;
    auto iter = num0.crbegin();
    while (iter != num0.crend()) {
      const int num = (*iter - '0') * num1 + carry;
      reverse_rtn.push_back(num % 10 + '0');
      carry = num / 10;
      ++iter;
    }
    if (carry) reverse_rtn.push_back(carry % 10 + '0');
    return {reverse_rtn.crbegin(), reverse_rtn.crend()};
  }
  string add(const string &num0, const string num1) {
    string reverse_rtn;
    int carry = 0;
    auto iter0 = num0.crbegin(), iter1 = num1.crbegin();
    while (iter0 != num0.crend() || iter1 != num1.crend()) {
      const int num = (iter0 == num0.crend() ? 0 : *iter0 - '0') + (iter1 == num1.crend() ? 0 : *iter1 - '0') + carry;
      reverse_rtn.push_back(num % 10 + '0');
      carry = num / 10;
      if(iter0 != num0.crend()) ++iter0;
      if(iter1 != num1.crend()) ++iter1;
    }
    if (carry) reverse_rtn.push_back(carry % 10 + '0');
    return {reverse_rtn.crbegin(), reverse_rtn.crend()};
  }
};

int main(void)
{
  Solution sln;
  // auto rtn = sln.add("123","999");
  // auto rtn = sln.multiply("12", 12);
  auto rtn = sln.multiply("12", "12");
  rtn = sln.multiply("123", "456");
  rtn = sln.multiply("123", "0");
  return 0;
}

