
#include <limits.h>

#include <string>
#include <vector>

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

class Solution_much_slower {
 public:
  string longestPalindrome(const string s) {
    int longest_palindrome = INT_MIN, start_pos = 0, end_pos = 1;
    const int str_size = s.size();
    vector<vector<char>> answer_cache(str_size, vector<char>(str_size, 'U'));
    for (int i = 0; i < str_size; ++i) answer_cache[i][i] = 'T';
    for (int i = 0; i < str_size - 1; ++i) {
      if (s[i] == s[i + 1]) {
        answer_cache[i][i + 1] = 'T';
        answer_cache[i + 1][i] = 'T';
      } else {
        answer_cache[i][i + 1] = 'F';
        answer_cache[i + 1][i] = 'F';
      }
      answer_cache[i][i + 1] = s[i] == s[i + 1] ? 'T' : 'F';
    }
    for (int length = 1; length < str_size; ++length) {
      for (int l_pos = 0; l_pos < str_size - length; ++l_pos) {
        const int r_pos = l_pos + length;
        if (s[l_pos] == s[r_pos] && answer_cache[l_pos + 1][r_pos - 1] == 'T') {
          answer_cache[l_pos][r_pos] = 'T';
          if (longest_palindrome < r_pos - l_pos) {
            longest_palindrome = r_pos - l_pos;
            start_pos = l_pos;
            end_pos = r_pos + 1;
          }
        } else
          answer_cache[l_pos][r_pos] = 'F';
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