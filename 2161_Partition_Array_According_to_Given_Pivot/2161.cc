
#include <memory.h>

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Solution {
 public:
  vector<int> pivotArray(vector<int>& nums, const int pivot) {
    vector<int> greater_nums;
    if (nums.size() < 256)
      greater_nums.reserve(nums.size());
    else if (nums.size() < 1024)
      greater_nums.reserve(256);
    else if (nums.size() < 5000)
      greater_nums.reserve(1024);
    else
      greater_nums.reserve(5000);
    int equal_count = 0, cur_index = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] < pivot)
        nums[cur_index++] = nums[i];
      else if (pivot < nums[i])
        greater_nums.push_back(nums[i]);
      else
        ++equal_count;
    }
    if (cur_index == nums.size()) return nums;

    for (const int cur_index_pos = cur_index; cur_index < cur_index_pos + equal_count; ++cur_index)
      nums[cur_index] = pivot;
    memcpy(nums.data() + cur_index, greater_nums.data(), greater_nums.size() * sizeof(int));
    return nums;
  }
};

int main(int argc, char* argv[]) {
  int test_arr[10] = {0};
  memset(test_arr, 1, 10 * sizeof(int));
  for (int i = 0; i < 10; ++i) {
    cout << test_arr[i] << "\n";
  }
  cout << std::endl;
  return 0;
}
