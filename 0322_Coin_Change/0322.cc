
#include <assert.h>
#include <limits.h>
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  int coinChange(const vector<int>& coins, int amount) {
    if (coins.empty()) return -1;
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    for (int i = 1; i < dp.size() && i < amount; ++i) {
      int min = -1;
      for (const int coin : coins) {
        if (i - coin < 0) continue;
        if (dp[i - coin] != -1 && dp[i - coin] + 1 < min)
          min = dp[i - coin] + 1;
      }
      dp[i] = min;
    }

  }

 private:

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
  // int rtn = sln.coinChange({186, 419, 83, 408}, 6249);
  // assert(3 == sln.coinChange({1, 2, 5}, 11));
  int rtn = sln.coinChange({2}, 3);
  return 0;
}