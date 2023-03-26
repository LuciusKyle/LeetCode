
#include <assert.h>
#include <time.h>

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  Solution(const vector<int>& nums) : original_vec_(nums), random_vec_(nums) {
    srand(time(nullptr));
  }

  vector<int> reset() { return original_vec_; }

  vector<int> shuffle() {
    for (int i = 0; i < random_vec_.size() - 1; ++i) {
      const int exchange_index = rand() % (random_vec_.size() - i) + i;
      const int temp_val = random_vec_[exchange_index];
      random_vec_[exchange_index] = random_vec_[i];
      random_vec_[i] = temp_val;
    }
    return random_vec_;
  }

 private:
  const vector<int>& original_vec_;
  vector<int> random_vec_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
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
