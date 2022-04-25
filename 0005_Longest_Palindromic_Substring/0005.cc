
#include <string>
#include <vector>
#include <limits.h>

using std::string;
using std::vector;

class Solution {
 public:
  string longestPalindrome(const string s) {
    int longest_palindrome = INT_MIN;
    int start_pos = 0, end_pos = 0;
    for (int i = 0; i < s.size(); ++i) {
      int l_pos = i, r_pos = i;
      while (0 <= l_pos && r_pos < s.size() && s[l_pos] == s[r_pos]) {
        --l_pos;
        ++r_pos;
      }
      if (longest_palindrome < r_pos - l_pos) {
        start_pos = l_pos + 1;
        end_pos = r_pos;
        longest_palindrome = r_pos - l_pos;
      }
      l_pos = i, r_pos = i + 1;
      while (0 <= l_pos && r_pos < s.size() && s[l_pos] == s[r_pos]) {
        --l_pos;
        ++r_pos;
      }
      if (longest_palindrome < r_pos - l_pos) {
        start_pos = l_pos + 1;
        end_pos = r_pos;
        longest_palindrome = r_pos - l_pos;
      }
    }
    return {s.cbegin() + start_pos, s.cbegin() + end_pos};
  }
};

int main(void) {
  Solution sln;
  string rtn = sln.longestPalindrome("abaqwerabcfcba");
  rtn = sln.longestPalindrome("abaqwerabba");
  rtn = sln.longestPalindrome("abaqweraa");
  rtn = sln.longestPalindrome("a");
  rtn = sln.longestPalindrome("");
  rtn = sln.longestPalindrome("ab");
  rtn = sln.longestPalindrome("cbbd");

  return 0;
}