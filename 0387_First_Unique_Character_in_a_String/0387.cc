
#include <string>

using std::string;

class Solution {
 public:
  int firstUniqChar(const string s) {
    size_t dict[26] = {0};
    for (const auto ch : s) ++(dict[ch - 'a']);
    int rtn = 0;
    for (const auto ch : s) {
      if (dict[ch - 'a'] == 1) return rtn;
      ++rtn;
    }
    return -1;
  }
};

int main(void) {
  Solution sln;
  int rtn = sln.firstUniqChar("leetcode");
  return 0;
}