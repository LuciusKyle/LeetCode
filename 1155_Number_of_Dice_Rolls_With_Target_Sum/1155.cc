
#include <algorithm>
#include <vector>

using std::vector;

// beats 87%.
constexpr int kModuloBase = 1000000007;
class Solution {
 public:
  int numRollsToTarget(const int n, const int k, const int target) {
    size_t answer_cache[30][1001] = {0};
    for (int i = 1; i <= std::min(k, target); ++i)
      answer_cache[0][i] = 1;
    for (int i = 0; i + 1 < n; ++i)
      for (int j = 1; j <= target; ++j)
        for (int l = 1; l <= k && l + j <= target; ++l)
          answer_cache[i + 1][l + j] = (answer_cache[i + 1][l + j] + answer_cache[i][j]) % kModuloBase;

    return answer_cache[n - 1][target];
  }
};

/*
// my first solution. correct answer, only beats 6%.
constexpr int kModuloBase = 1000000007;
class Solution {
 public:
  int numRollsToTarget(const int n, const int k, const int target) {
    vector<vector<size_t>> answer_cache(n, vector<size_t>(target + 1, 0));
    for (int i = 1; i <= std::min(k, target); ++i)
      answer_cache.front()[i] = 1;
    for (int i = 0; i + 1 < n; ++i) {
      for (int j = 1; j <= target; ++j) {
        for (int l = 1; l <= k && l + j <= target; ++l) {
          answer_cache[i + 1][l + j] = (answer_cache[i + 1][l + j] + answer_cache[i][j]) % kModuloBase;
        }
      }
    }
    return answer_cache.back().back();
  }
};
*/