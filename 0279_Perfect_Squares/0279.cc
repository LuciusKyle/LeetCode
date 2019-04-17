
#include <limits.h>
#include <vector>

using std::vector;

class Solution {
 public:
  int numSquares(const int n) {
    vector<int> squars;
    for (int i = 1; i * i <= n; ++i) {
      squars.push_back(i * i);
    }
    return coinChange(squars, n);
  }

 private:

  // function from problem 322.
  int coinChange(const vector<int>& coins, const int amount) {
    if (coins.empty()) return -1;
    vector<int> dp(1, 0);
    for (int i = 1; i < amount + 1; ++i) {
      dp.push_back(-1);
      int min_coin_count = INT_MAX;
      for (const int coin : coins) {
        if (i - coin < 0 || dp[i - coin] == -1) continue;
        if (dp[i - coin] < min_coin_count) min_coin_count = dp[i - coin];
      }
      if (INT_MAX != min_coin_count) dp.back() = min_coin_count + 1;
    }
    return dp.back();
  }

  // not used in this case.
  int LeastCommonMultiple(const vector<int>& coins, int max_coin) {
    if (coins.empty()) return 0;
    int multiple_time = 1;
    bool keep_running = true;
    while (keep_running) {
      keep_running = false;
      for (const int coin : coins)
        if ((max_coin * multiple_time) % coin != 0) {
          ++multiple_time;
          keep_running = true;
          break;
        }
    }
    return max_coin * multiple_time;
  }
};

int main(void) {
  Solution sln;

  return 0;
}
