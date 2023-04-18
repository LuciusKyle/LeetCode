
#include <assert.h>

#include <string>

using std::string;

class Solution {
 public:
  string removeKdigits(const string num, int k) {
    string rtn;
    rtn.reserve(num.size() - k + 1);
    int i = 0, pop_count = 0;
    for (; i < num.size(); ++i) {
      while (pop_count < k && !rtn.empty() && num[i] < rtn.back()) {
        rtn.pop_back();
        ++pop_count;
      }
      rtn.push_back(num[i]);
    }
    for (int i = pop_count; i < k; ++i)
      rtn.pop_back();
    int leading_zeroes = 0;
    while (leading_zeroes < rtn.size() && rtn[leading_zeroes] == '0')
      ++leading_zeroes;
    if (leading_zeroes == rtn.size()) return "0";
    return {rtn.begin() + leading_zeroes, rtn.end()};
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
