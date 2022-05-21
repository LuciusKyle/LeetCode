
#include <assert.h>
#include <limits.h>

#include <algorithm>
#include <vector>

using std::vector;

// DFS, beats 88%.
class Solution_BFS {
 public:
  int coinChange(const vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    vector<int> next_level(1, 0);
    int level = 1;
    do {
      vector<int> current_level;
      for (const int pos : next_level)
        for (const int coin : coins)
          if (pos + coin < amount + 1 && dp[pos + coin] == -1) {
            dp[pos + coin] = level;
            if (pos + coin == amount) return level;
            current_level.push_back(pos + coin);
          }
      ++level;
      next_level = current_level;
    } while (!next_level.empty());
    return dp.back();
  }
};

// beats 90%.
class Solution {
 public:
  int coinChange(const vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    for (int i = 1; i < amount + 1; ++i) {
      int min_coin_count = INT_MAX;
      for (const int coin : coins)
        if (coin <= coin && dp[i - coin] != -1 && dp[i - coin] < min_coin_count)
          min_coin_count = dp[i - coin];

      if (INT_MAX != min_coin_count) dp[i] = min_coin_count + 1;
    }
    return dp.back();
  }
};

int main(void) {
  Solution sln;
  int rtn = sln.coinChange({186, 419, 83, 408}, 6249);
  assert(3 == sln.coinChange({1, 2, 5}, 11));
  rtn = sln.coinChange({2}, 3);
  return 0;
}