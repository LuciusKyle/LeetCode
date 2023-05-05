
#include <assert.h>
#include <limits.h>

#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    std::sort(coins.begin(), coins.end());
    while (coins.back() > amount) coins.pop_back();
    if (coins.back() == amount) return 1;
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    for (int i = 1; i < amount + 1; ++i) {
      int min_coin_count = INT_MAX;
      for (const int coin : coins)
        if (coin <= i && dp[i - coin] != -1 && dp[i - coin] < min_coin_count)
          min_coin_count = dp[i - coin];
      if (INT_MAX != min_coin_count) dp[i] = min_coin_count + 1;
    }
    return dp.back();
  }
};

int main(void) {
  Solution sln;
  return 0;
}