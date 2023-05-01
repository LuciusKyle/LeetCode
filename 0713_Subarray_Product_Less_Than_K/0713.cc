
#include <vector>

using std::vector;

class Solution {
 public:
  int numSubarrayProductLessThanK(const vector<int>& nums, int k) {
    if (k < 2) return 0;
    int l_index = -1, curr_product = 1, sub_arr_count = 0;
    for (int r_index = 0; r_index < nums.size(); ++r_index) {
      curr_product *= nums[r_index];
      while (k <= curr_product)
        curr_product /= nums[++l_index];
      sub_arr_count += (r_index - l_index);
    }
    return sub_arr_count;
  }
};

int main(int argc, char* argv[]) {
  vector<int> test_vec{10, 5, 2, 6};
  Solution sln;
  sln.numSubarrayProductLessThanK(test_vec, 100);
  return 0;
}