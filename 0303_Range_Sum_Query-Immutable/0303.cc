
#include <assert.h>

#include <algorithm>
#include <vector>

using std::vector;

class NumArray {
 public:
  NumArray(const vector<int>& nums) {
    prefix_sum_.reserve(nums.size() + 1);
    prefix_sum_.push_back(0);
    for (const int num : nums) {
      prefix_sum_.push_back(prefix_sum_.back() + num);
    }
  }

  int sumRange(int left, int right) { return prefix_sum_[right + 1] - prefix_sum_[left]; }

 private:
  vector<int> prefix_sum_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

int main(void) {
  NumArray obj({1});
  assert(1 == obj.sumRange(0, 0));

  return 0;
}
