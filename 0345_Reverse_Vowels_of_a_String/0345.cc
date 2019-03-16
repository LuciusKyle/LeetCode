
#include <assert.h>
#include <string>

using std::string;

class Solution {
 public:
  string reverseVowels(string s) {
    size_t begin_index = 0;
    size_t end_index = s.empty() ? s.size() : s.size() - 1;
    while (begin_index < end_index) {
      if (isVowel(s[begin_index]))
        for (; begin_index < end_index; --end_index)
          if (isVowel(s[end_index])) {
            s[begin_index] ^= s[end_index];
            s[end_index] ^= s[begin_index];
            s[begin_index] ^= s[end_index];
            --end_index;
            break;
          }
      ++begin_index;
    }
    return s;
  }

 private:
  bool isVowel(const char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
  }
};

int main(void) {
  Solution sln;
  assert("leotcede" == sln.reverseVowels("leetcode"));
  return 0;
}