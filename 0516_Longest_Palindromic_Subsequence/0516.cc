
#include <string>
#include <vector>

using std::string;
using std::vector;

// beats 73%, space complexity is O(n^2), could be O(n).
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
    for (int len = 2; len < n; ++len)
      for (int start = 0; start + len < n; ++start)
        if (s[start] == s[start + len])
          dp[start][start + len] = 2 + dp[start + 1][start + len - 1];
        else
          dp[start][start + len] = std::max(dp[start][start + len - 1], dp[start + 1][start + len]);
    return dp[0][n - 1];
  }
};

int main(int argc, char *argv[]) {
  Solution sln;
  sln.longestPalindromeSubseq("aa");
  return 0;
}
