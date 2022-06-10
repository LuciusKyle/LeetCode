
#include <assert.h>
#include <algorithm>
#include <array>
#include <string>

using std::string;

class Solution {
 public:
  int lengthOfLongestSubstring(const string s) {
    int dict[128] = {0};
    int max_len = 0;
    for (int i = 1, start = 0; i <= s.size(); ++i) {
      if (start < dict[s[i - 1]]) start = dict[s[i - 1]];
      dict[s[i - 1]] = i;
      if (max_len < i - start) max_len = i - start;
    }
    return max_len;
  }
};

int main(void) {
  Solution sln;
  assert(1 == sln.lengthOfLongestSubstring("a"));
  assert(1 == sln.lengthOfLongestSubstring("bbbbbb"));
  assert(3 == sln.lengthOfLongestSubstring("abcabcbb"));
  assert(3 == sln.lengthOfLongestSubstring("pwwkew"));
  return 0;
}