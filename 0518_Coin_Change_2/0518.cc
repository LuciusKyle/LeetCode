
#include <assert.h>
#include <vector>

using std::vector;

class Solution {
 public:
  int change(int amount, const vector<int>& coins) {
    if (coins.empty()) return 0;
    if (amount == 0) return 1;
    vector<int> result(amount + 1, 0);
    for (size_t i = 0; i < size_t(amount + 1); ++i)
      for (const int coin : coins)
        if (i + coin < size_t(amount + 1)) result[i + coin] = result[i] + 1;
    return result.back();
  }
};

int main(void ) {
  Solution sln;
  assert(4 == sln.change(5, {1, 2, 5}));
  assert(0 == sln.change(3, {2}));
  return 0;
}
