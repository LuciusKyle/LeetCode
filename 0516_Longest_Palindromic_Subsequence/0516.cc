
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int longestPalindromeSubseq(const string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
    return longestPalindromeSubseq(s, 0, s.size() - 1, dp);
  }

 private:
  int longestPalindromeSubseq(const string &s, int start, int end, vector<vector<int>> &dp) {
    if (dp[start][end] != -1) return dp[start][end];
    if (start == end) {
      dp[start][end] = 1;
      return 1;
    }
    if (start + 1 == end) {
      dp[start][end] = s[start] == s[end] ? 2 : 1;
      return dp[start][end];
    }
    dp[start][end] = std::max(longestPalindromeSubseq(s, start + 1, end - 1, dp) + (s[start] == s[end] ? 2 : 0), std::max(longestPalindromeSubseq(s, start + 1, end, dp), longestPalindromeSubseq(s, start, end - 1, dp)));
    return dp[start][end];
  }
};
