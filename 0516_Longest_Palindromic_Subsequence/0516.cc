
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int longestPalindromeSubseq(const string s) {
    const int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      dp[i][i] = 1;
      if (i != 0)
        dp[i - 1][i] = s[i - 1] == s[i] ? 2 : 1;
      if (i != n - 1)
        dp[i][i + 1] = s[i] == s[i + 1] ? 2 : 1;
    }
    // return longestPalindromeSubseq(s, 0, n - 1, dp); // faster, but still beats 5%.
    for (int len = 2; len < n; ++len) {
      for (int start = 0; start + len < n; ++start) {
        dp[start][start + len] = std::max(dp[start + 1][start + len - 1] + (s[start] == s[start + len] ? 2 : 0), std::max(dp[start][start + len - 1], dp[start + 1][start + len]));
      }
    }
    return dp[0][n - 1];
  }

 private:
  int longestPalindromeSubseq(const string &s, int start, int end, vector<vector<int>> &dp) {
    if (dp[start][end] != -1) return dp[start][end];
    dp[start][end] = std::max(longestPalindromeSubseq(s, start + 1, end - 1, dp) + (s[start] == s[end] ? 2 : 0), std::max(longestPalindromeSubseq(s, start + 1, end, dp), longestPalindromeSubseq(s, start, end - 1, dp)));
    return dp[start][end];
  }
};

int main(int argc, char *argv[]) {
  Solution sln;
  sln.longestPalindromeSubseq("aa");
  return 0;
}
