
#include <string>

using std::string;

class Solution {
 public:
  string reverseWords(string s) {
    int start = 0;
    int len = 0;
    for (int i = 0; i <= s.size(); ++i) {
      if (s[i] == ' ' || s[i] == '\0') {
        reverseWord(&s[start], len - 1);
        start = i + 1;
        len = 0;
      } else
        ++len;
    }
    return s;
  }

 private:
  void reverseWord(char *str, int len) {
    if (len == 0) return; 
    int i = 0;
    do {
      str[i] ^= str[len];
      str[len] ^= str[i];
      str[i] ^= str[len];
      ++i; --len;
    } while (0 < len - i);
  }
};

int main(void) {
  Solution sln;

  string test_sample = "Let's take LeetCode contest";
  string rtn = sln.reverseWords(test_sample);
  rtn = sln.reverseWords("I love u");
  return 0;
}
