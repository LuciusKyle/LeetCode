
#include <vector>

using std::vector;

class Solution {
 public:
  int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    vector<vector<int>> dp(piles.size(), vector<int>(k + 1, -1));
    dp[0][0] = 0;
    for (int i = 0; i < k && i < piles[0].size(); ++i)
      dp[0][i + 1] = dp[0][i] + piles[0][i];
    for (int pile_index = 1; pile_index < piles.size(); ++pile_index) {
      dp[pile_index][0] = 0;
      vector<int> prefix_sum;
      prefix_sum.reserve(piles[pile_index].size());
      prefix_sum.push_back(0);
      for (int i = 0; i < piles[pile_index].size(); ++i)
        prefix_sum.push_back(prefix_sum.back() + piles[pile_index][i]);
      for (int count = 1; count <= k; ++count) {
        int max_coins = 0;
        for (int i = 0; i <= count; ++i) {
          if (dp[pile_index - 1][i] == -1 || prefix_sum.size() <= count - i) continue;
          if (max_coins < dp[pile_index - 1][i] + prefix_sum[count - i]) {
            max_coins = dp[pile_index - 1][i] + prefix_sum[count - i];
          }
        }
        dp[pile_index][count] = max_coins;
      }
    }
    return dp.back().back();
  }
};
