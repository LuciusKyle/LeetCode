
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int minimumDeleteSum(const string s1, const string s2) {
    const int len1 = s1.size(), len2 = s2.size();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
    for (int i = len2 - 1; 0 <= i; --i)
      dp[len1][i] = dp[len1][i + 1] + int(s2[i]);
    for (int i = len1 - 1; 0 <= i; --i)
      dp[i][len2] = dp[i + 1][len2] + int(s1[i]);
    for (int i1 = len1 - 1; 0 <= i1; --i1)
      for (int i2 = len2 - 1; 0 <= i2; --i2)
        dp[i1][i2] = std::min(std::min(int(s1[i1]) + dp[i1 + 1][i2], int(s2[i2]) + dp[i1][i2 + 1]), (s1[i1] == s2[i2] ? 0 : int(s1[i1]) + int(s2[i2])) + dp[i1 + 1][i2 + 1]);
    return dp[0][0];
  }
};

int main(int argc, char *argv[]) {
  Solution sln;
  sln.minimumDeleteSum("delete", "leet");
  return 0;
}
