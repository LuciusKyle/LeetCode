
#include <vector>
#include <numeric>
#include <inttypes.h>

using std::vector;

constexpr size_t s1 = sizeof(int);
constexpr size_t s2 = sizeof(int64_t);

class Solution {
 public:
  double findMaxAverage(const vector<int>& nums, int k) {
    int64_t sum = 0;
    for (int i = 0; i < k; ++i) sum += nums[i]; // accumulate by myself, 91% beat.
    // int64_t sum = std::accumulate(nums.cbegin(), nums.cbegin() + k, 0); // using std::accumulate(), 33% beat.
    int64_t max = sum;
    for (int i = k; i < nums.size(); ++i) {
      sum -= nums[i - k];
      sum += nums[i];
      if (max < sum) max = sum;
    }
    return double(max) / k;
  }
};

int main(void) {
  Solution sln;
  double rtn = sln.findMaxAverage({1, 12, -5, -6, 50, 3}, 4);
  return 0;
}
