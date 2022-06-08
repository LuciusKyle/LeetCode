
#include <string>

using std::string;

class Solution {
 public:
  int removePalindromeSub(const string s) {
    const size_t mid = s.size() / 2;
    for (size_t i = 0; i < mid; ++i)
      if (s[i] != s[s.size() - 1 - i]) return 2;

    return 1;
  }
};