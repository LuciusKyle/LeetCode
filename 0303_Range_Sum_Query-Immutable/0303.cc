
#include <assert.h>
#include <vector>

using std::vector;

constexpr size_t kGrainSize = 2;

class NumArray {
 public:
  NumArray(const vector<int> nums) : nums_(nums) {
    static_assert(0 != kGrainSize);
    sums_cache_.push_back(vector<int>());
    int temp_sum = 0;
    for (size_t i = 0; i < nums_.size(); ++i) {
      temp_sum += nums[i];
      if (i % kGrainSize == 0)
        sums_cache_[0].push_back(temp_sum);
    }
    sums_cache_[0].shrink_to_fit();
    for (size_t i = 1; i < nums_.size() / kGrainSize; ++i) {
      sums_cache_.push_back(vector<int>());
      for (size_t ii = i; ii < nums_.size() / kGrainSize; ++ii) {
        temp_sum = sums_cache_[i - 1][ii];
        for (size_t iii = (i - 1) * kGrainSize; iii < i * kGrainSize; ++iii)
          temp_sum -= nums_[iii];
        sums_cache_[i].push_back(temp_sum);
      }
      sums_cache_[i].shrink_to_fit();
    }
  }

  int sumRange(const int begin, const int end) {
    int rtn =
        sums_cache_[begin / kGrainSize][end / kGrainSize - begin / kGrainSize];
    if (begin % kGrainSize != 0)
      for (size_t i = begin / kGrainSize * kGrainSize;
           i < begin / kGrainSize * kGrainSize + begin % kGrainSize && i < nums_.size(); ++i)
        rtn -= nums_[i];
    if (end % kGrainSize != 0)
      for (size_t i = end / kGrainSize * kGrainSize + 1; i <= end; ++i)
        rtn += nums_[i];

    return rtn;
  }

 private:
  const vector<int> nums_;
  vector<vector<int>> sums_cache_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

int main(void) {
  // NumArray obj({0, 1, 2, 3});
  // assert(3 == obj.sumRange(0, 2));
  // assert(6 == obj.sumRange(0, 3));
  // assert(1 == obj.sumRange(1, 1));

  // NumArray obj({0, 1, 2, 3, 4, 5});
  // assert(3 == obj.sumRange(0, 2));
  // assert(14 == obj.sumRange(2, 5));
  // assert(15 == obj.sumRange(0, 5));

  NumArray obj({-8261, 2300, -1429, 6274, 9650, -3267, 1414, -8102, 6251, -5979, -5291, -4616, -4703});
  obj.sumRange(12, 12);
  //for (int i = 0; i <= 12; ++i)
  //  for (int j = i; j <= 12; ++j) obj.sumRange(i, j);

  return 0;
}
