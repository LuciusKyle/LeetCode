
#include <assert.h>
#include <string>

using std::string;

// s = "3[a]2[bc]", return "aaabcbc".
// s = "3[a2[c]]", return "accaccacc".
// s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
class Solution {
 public:
  string decodeString(const string s) {
    string rtn;
    for(size_t i = 0; i < s.size(); ++i) {
      if ('0' - 1 < s[i] && s[i] < '9' + 1) {
        const size_t repeat_count = atoi(&(s[i]));
        size_t temp_len = 0;
        const string repeat_str = oneGroup(&(s[i]), temp_len);
        for(size_t ii=0;ii<repeat_count;++ii)
          rtn.append(repeat_str);
        i += temp_len;
      } else {
        rtn.push_back(s[i]);
      }
    }
    return rtn;
  }

 private:
  [[gnu::const]] string oneGroup(const char *str, size_t &str_len) {
    size_t start_index = 0;
    size_t end_index = 0;
    while (str[end_index] != ']') {
      if (str[end_index] == '[') start_index = end_index + 1;
      ++end_index;
    }
    str_len = end_index;
    return string(str + start_index, end_index - start_index);
  }
};

int main(void) {
  Solution sln;
  assert(sln.decodeString("3[a]2[bc]") == "aaabcbc");
  assert(sln.decodeString("2[abc]3[cd]ef") == "abcabccdcdcdef");
  // s = "3[a2[c]]", return "accaccacc".
  return 0;
}
