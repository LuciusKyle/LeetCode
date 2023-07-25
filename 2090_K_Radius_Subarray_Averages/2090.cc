
#include <numeric>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> getAverages(const vector<int>& nums, int k) {
    vector<int> avg_within_radius(nums.size(), -1);
    const int window_size = 1 + 2 * k;
    long curr_accumulation = std::accumulate(nums.cbegin(), nums.cbegin() + std::min(window_size, int(nums.size())), 0l);
    if (window_size <= nums.size()) avg_within_radius[k] = curr_accumulation / window_size;
    for (int i = k + 1; i + k < nums.size(); ++i) {
      curr_accumulation -= nums[i - k - 1];
      curr_accumulation += nums[i + k];
      avg_within_radius[i] = curr_accumulation / window_size;
    }
    return avg_within_radius;
  }
};

int main(int argc, char* argv[]) {
  vector<int> test_vec{7, 4, 3, 9, 1, 8, 5, 2, 6};
  int a = std::accumulate(test_vec.cbegin(), test_vec.cbegin() + 1, 0);
  a = std::accumulate(test_vec.cbegin(), test_vec.cbegin() + 2, 0);
  a = std::accumulate(test_vec.cbegin(), test_vec.cbegin(), 0);

  Solution sln;
  sln.getAverages(test_vec, 3);
  return 0;
}
