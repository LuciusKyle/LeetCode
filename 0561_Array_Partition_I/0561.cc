
#include <algorithm>
// #include <execution>
#include <vector>

using std::vector;

// 48% beat.
class Solution1 {
 public:
  int arrayPairSum(vector<int>& nums) {
    // std::sort(std::execution::par, nums.begin(), nums.end());
    std::sort(nums.begin(), nums.end());
    int ret = 0;
    for (int i = 0; i < nums.size(); i += 2) ret += nums[i];

    return ret;
  }
};

// 96% beat.
class Solution {
 public:
  int arrayPairSum(const vector<int>& nums) {
    int* counter = new int[20001]{0};
    for (const int num : nums) ++counter[10000 + num];

    int sum = 0;
    bool counter_odd = true;
    for (int i = 0; i < 20001; ++i) {
      const int val = counter[i];
      if (0 != val) {
        if (counter_odd)
          sum += (i - 10000) * ((val + 1) / 2);
        else
          sum += (i - 10000) * (val / 2);
        if (val % 2) counter_odd = !counter_odd;
      }
    }

    delete[] counter;
    return sum;
  }
};

int main(void) {
  Solution sln;
  return 0;
}