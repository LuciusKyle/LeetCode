
#include <assert.h>
#include <array>
#include <string>

using std::array;
using std::string;

std::array<char, 8> verify_same_digit{0};

class Solution {
 public:
  string removeKdigits(const string num, int k) {
    string rtn;
    rtn.reserve(num.size() - k + 1);
    for (const char ch : num) {
      while (k != 0 && !rtn.empty() && ch < rtn.back()) {
        rtn.pop_back();
        --k;
      }
      rtn.push_back(ch);
    }
    while (k != 0) {
      rtn.pop_back();
      --k;
    }
    auto begin_iter = rtn.cbegin();
    while (*begin_iter == '0') ++begin_iter;
    if (begin_iter == rtn.cend())
      return "0";
    else
      return {begin_iter, rtn.cend()};
  }
};

int main(void) {
  char a[8] = {"1234567"};
  char b[8] = {"1234567"};
  assert(*(reinterpret_cast<size_t *>(a)) == *(reinterpret_cast<size_t *>(b)));

  Solution sln;
  auto rtn = sln.removeKdigits("1432219", 3);
  rtn = sln.removeKdigits("109", 2);
  return 0;
}
