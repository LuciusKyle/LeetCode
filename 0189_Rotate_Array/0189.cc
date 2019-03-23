
#include <memory.h>
#include <vector>

using std::vector;

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    if (nums.empty()) return;
    k %= nums.size();
    if (k == 0) return;
    int* temp_vec = new int[nums.size()];
    memcpy(temp_vec, &(nums.data()[nums.size() - k]), k * sizeof(int));
    memcpy(temp_vec + k, nums.data(), (nums.size() - k) * sizeof(int));
    memcpy(nums.data(), temp_vec, nums.size() * sizeof(int));
    delete[] temp_vec;
  }
};

int main(int argc, char const* argv[]) {
  vector test_sample{1, 2, 3, 4, 5, 6, 7};
  Solution sln;
  sln.rotate(test_sample, 3);
  return 0;
}
