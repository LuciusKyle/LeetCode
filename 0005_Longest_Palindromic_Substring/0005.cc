
#include <string>

using std::string;

class Solution {
 public:
  string longestPalindrome(string s) {
    int max_length = 0;
    int start_pos = 0;
    for (int /*can't use unsigned type*/ i = 0; i < s.size(); ++i) {
      int left_cursor = i, right_cursor = i;
      int palindrome_length = 0;
      bool found_palindrome = false;
      while (left_cursor >= 0 && right_cursor < s.size()) {
        if (s[left_cursor] == s[right_cursor])
          palindrome_length = right_cursor - left_cursor + 1;
        else {
          --left_cursor;
          ++right_cursor;
          break;
        }
        --left_cursor;
        ++right_cursor;
      }
      if (palindrome_length > max_length) {
        max_length = palindrome_length;
        start_pos = left_cursor + 1;
      }
      left_cursor = i;
      right_cursor = i + 1;
      found_palindrome = false;
      while (left_cursor >= 0 && right_cursor < s.size()) {
        if (s[left_cursor] == s[right_cursor])
          palindrome_length = right_cursor - left_cursor + 1;
        else {
          --left_cursor;
          ++right_cursor;
          break;
        }
        --left_cursor;
        ++right_cursor;
      }
      if (palindrome_length > max_length) {
        max_length = palindrome_length;
        start_pos = left_cursor + 1;
      }
    }
    return string(s.begin() + start_pos, s.begin() + start_pos + max_length);
  }
};

int main(void) {
  Solution sln;
  auto rtn = sln.longestPalindrome("abaqwerabcfcba");
  rtn = sln.longestPalindrome("abaqwerabba");
  rtn = sln.longestPalindrome("abaqweraa");
  rtn = sln.longestPalindrome("a");
  rtn = sln.longestPalindrome("");
  rtn = sln.longestPalindrome("ab");
  rtn = sln.longestPalindrome("cbbd");

  return 0;
}