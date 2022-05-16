
#include <assert.h>

#include <array>
#include <vector>

using std::array;
using std::vector;

constexpr int kMaxAmount = 5000;

class Solution {
 public:
  int change(const int amount, const vector<int>& coins) {
    vector<vector<int>> answer_cache(coins.size(), vector<int>(amount + 1));
    for (int i = 0; i < answer_cache[0].size(); i += coins[0])
      answer_cache[0][i] = 1;

    for (size_t i = 1; i < answer_cache.size(); ++i) {
      for (int j = 0; j < amount + 1; ++j) {
        if (answer_cache[i - 1][j]) {
          for (int k = j; k < amount + 1; k += coins[i]) {
            answer_cache[i][k] += answer_cache[i - 1][j];
          }
        }
      }
    }
    return answer_cache[coins.size() - 1][amount];
  }

 private:
};

int main(void) {
  Solution sln;
  int rtn = sln.change(5, {1, 2, 5});
  assert(4 == rtn);
  rtn = sln.change(3, {2});
  assert(0 == rtn);
  return 0;
}
