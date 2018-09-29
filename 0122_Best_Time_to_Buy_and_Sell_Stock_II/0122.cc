
#include <assert.h>
#include <vector>

using std::vector;

class Solution {
 public:
  int maxProfit(const vector<int>& prices) {
    int profit = 0;
    for (int i = 0; i < static_cast<int>(prices.size()) - 1; ++i)
      profit +=
          0 < (prices[i + 1] - prices[i]) ? (prices[i + 1] - prices[i]) : 0;
    return profit;
  }
};

int main(void) {
  Solution sln;
  assert(7 == sln.maxProfit({7, 1, 5, 3, 6, 4}));
  assert(1 == sln.maxProfit({1, 2}));
  assert(0 == sln.maxProfit({1, 1}));
  assert(0 == sln.maxProfit({1}));
  assert(0 == sln.maxProfit(vector<int>()));
  return 0;
}
