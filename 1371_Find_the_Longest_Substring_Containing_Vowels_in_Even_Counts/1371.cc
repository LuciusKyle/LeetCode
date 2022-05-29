
#include <assert.h>

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int findTheLongestSubstring(string s) {
    const size_t str_size = s.size();
    s.push_back(0);
    char pre_char = s[0];
    s[0] = 0;
    for (size_t i = 1; i <= str_size; ++i) {
      const char cur_char = s[i];
      switch (pre_char) {
        case 'a':
          s[i] = s[i - 1] ^ 1 << 0;
          break;
        case 'e':
          s[i] = s[i - 1] ^ 1 << 1;
          break;
        case 'i':
          s[i] = s[i - 1] ^ 1 << 2;
          break;
        case 'o':
          s[i] = s[i - 1] ^ 1 << 3;
          break;
        case 'u':
          s[i] = s[i - 1] ^ 1 << 4;
          break;
        default:
          s[i] = s[i - 1];
          break;
      }
      pre_char = cur_char;
    }

    for (int len = str_size; 0 < len; --len)
      for (int start_index = str_size - len + 1; 0 < start_index; --start_index)
        if (s[start_index - 1] == s[start_index + len - 1])
          return len;
    return 0;
  }
};

int main(int argc, char* argv[]) {
  const string test_str = argc == 2 ? argv[1] : "leetcodeisgreat";
  Solution sln;
  int rtn = sln.findTheLongestSubstring(test_str);
  assert(rtn == 5);
  return 0;
}