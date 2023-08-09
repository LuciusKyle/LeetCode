
#include <assert.h>

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  int stoneGameVII(const vector<int>& stones) {
    const int n = stones.size();
    prefix_sum_.reserve(n + 1);
    prefix_sum_.push_back(0);
    for (const int val : stones)
      prefix_sum_.push_back(prefix_sum_.back() + val);
    dp_.assign(n, vector<int>(n + 1, -1));
    for (int i = 0; i < n; ++i)
      dp_[i][i + 1] = 0;
    return maxDiff(stones, 0, n);
  }
  void clearCache() { prefix_sum_.clear(); }

 private:
  vector<int> prefix_sum_;
  vector<vector<int>> dp_;

  int maxDiff(const vector<int>& stones, int start, int end) {
    if (dp_[start][end] != -1) return dp_[start][end];
    // if (start + 1 == end) return 0;
    const int remove_left = (prefix_sum_[end] - prefix_sum_[start + 1]) - maxDiff(stones, start + 1, end);
    const int remove_right = (prefix_sum_[end - 1] - prefix_sum_[start]) - maxDiff(stones, start, end - 1);
    dp_[start][end] = std::max(remove_left, remove_right);
    return dp_[start][end];
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  assert(6 == sln.stoneGameVII({5, 3, 1, 4, 2}));
  sln.clearCache();
  assert(122 == sln.stoneGameVII({7, 90, 5, 1, 100, 10, 10, 2}));
  vector<int> test_vec;
  for (int i = 1; i < argc; ++i) {
    test_vec.push_back(atoi(argv[i]));
  }
  sln.clearCache();
  if (2 <= test_vec.size())
    cout << sln.stoneGameVII(test_vec) << endl;
  return 0;
}
