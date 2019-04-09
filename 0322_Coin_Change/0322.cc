
#include <limits.h>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
 public:
  int coinChange(const vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    int rtn = coinChange_helper(coins, amount);
    return rtn == INT_MAX ? -1 : rtn;
  }

 private:
  int coinChange_helper(const vector<int>& coins, const int amount) {
    if (dp_.count(amount) != 0) return dp_.at(amount);
    int rtn = INT_MAX;
    for (const int coin : coins) {
      if (0 < amount - coin) {
        if (coinChange_helper(coins, amount - coin) < rtn - 1)
          rtn = 1 + dp_.at(amount - coin);
      } else if (amount - coin < 0)
        continue;
      else {
        dp_.insert({amount, 1});
        return 1;
      }
    }
    if (rtn != INT_MAX) dp_.insert({amount, rtn});
    return rtn;
  }

  unordered_map<int, int> dp_;
};

int main(void) {
  Solution sln;

  return 0;
}