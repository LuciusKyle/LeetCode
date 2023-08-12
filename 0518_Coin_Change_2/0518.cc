
#include <assert.h>

#include <array>
#include <vector>

using std::array;
using std::vector;

class Solution {
 public:
  int change(const int amount, const vector<int>& coins) {
    vector<int> combinations(amount + 1);
    combinations[0] = 1;
    for (const int coin : coins)
      for (int i = 0; i < amount + 1 - coin; ++i)
        combinations[i + coin] += combinations[i];
    return combinations.back();
  }
};

int main(void) {
  Solution sln;
  int rtn = sln.change(5, {1, 2, 5});
  assert(4 == rtn);
  rtn = sln.change(3, {2});
  assert(0 == rtn);
  return 0;
}
