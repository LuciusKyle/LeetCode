#include <assert.h>
#include <limits.h>
#include <vector>

using std::vector;

class Solution {
 public:
  int maxProfit(const vector<int>& prices) {
    if (prices.empty()) return 0;
    int max_profit = 0;
#if 201402L < __cplusplus
    vector max_foresee_profit(prices.size(), prices.back());
#else
    vector<int> max_foresee_profit(prices.size(), prices.back());
#endif
    {
      int max_price = INT_MIN;
      for (int i = prices.size() - 1; i >= 0; --i) {
        if (max_price < prices[i]) max_price = prices[i];
        if (max_profit < max_price - prices[i])
          max_profit = max_price - prices[i];
        max_foresee_profit[i] = max_profit;
      }
    }
    int max_profit_two_transactions = 0;
    max_profit = 0;
    int min_price = INT_MAX;
    for (size_t i = 0; i < prices.size() - 1; ++i) {
      if (prices[i] < min_price) min_price = prices[i];
      if (max_profit < prices[i] - min_price)
        max_profit = prices[i] - min_price;
      if (max_profit_two_transactions < max_profit + max_foresee_profit[i])
        max_profit_two_transactions = max_profit + max_foresee_profit[i];
    }
    return max_profit_two_transactions;
  }
};

int main(void) {
  Solution sln;
  vector test_sample{3, 3, 5, 0, 0, 3, 1, 4};

  assert(6 == sln.maxProfit(test_sample));

  test_sample = {7, 6, 4, 3, 1};
  assert(0 == sln.maxProfit(test_sample));

  test_sample = {1, 2};
  assert(1 == sln.maxProfit(test_sample));

  test_sample = {1};
  assert(0 == sln.maxProfit(test_sample));

  test_sample = vector<int>();
  assert(0 == sln.maxProfit(test_sample));

  test_sample = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
  assert(13 == sln.maxProfit(test_sample));

  return 0;
}