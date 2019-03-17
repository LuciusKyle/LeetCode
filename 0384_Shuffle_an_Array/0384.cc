
#include <assert.h>
#include <iostream>
#include <random>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  Solution(const vector<int> nums) : original_vec_(nums) {
    // assert(!original_vec_.empty());
    // leetcode's test sample contains an empty vector;
  }

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() { return original_vec_; }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    if (original_vec_.empty()) return original_vec_;
    auto rtn = original_vec_;
    for (size_t i = rtn.size() - 1; i != 0; --i) {
      const size_t random_index = int_dist(rd) % (i + 1);
      if (random_index != i) {
        rtn[i] ^= rtn[random_index];
        rtn[random_index] ^= rtn[i];
        rtn[i] ^= rtn[random_index];
      }
    }
    return rtn;
  }

 private:
  const vector<int> original_vec_;
  std::random_device rd;
  std::uniform_int_distribution<size_t> int_dist;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

int main(void) {
  Solution sln({1, 2, 3, 4, 5, 6});
  for (size_t i = 0; i < 30; ++i) {
    auto rtn = sln.shuffle();
    for (const auto n : rtn) cout << n << '\t';
    cout << '\n';
  }
  return 0;
}
