
#include <algorithm>
#include <unordered_map>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> recoverArray(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::unordered_map<int, int> nums_count;
    nums_count.reserve(nums.size() + 40);
    for (const int num : nums) ++nums_count[num];
    vector<int> origin_vec;
    origin_vec.reserve(nums.size() / 2);
    for (int index_distance = 1; index_distance <= nums.size() / 2; ++index_distance) {
      const int diff = nums[index_distance] - nums[0];
      if (diff == 0 || diff % 2 == 1) continue;
      auto nums_count_copy = nums_count;
      bool this_is_the_diff = true;
      for (const int num : nums) {
        while (nums_count_copy.count(num) != 0) {
          if (nums_count_copy.count(num + diff) == 0) {
            this_is_the_diff = false;
            break;
          }
          origin_vec.push_back(num + diff / 2);
          --nums_count_copy[num];
          --nums_count_copy[num + diff];
          if (nums_count_copy[num] == 0) nums_count_copy.erase(num);
          if (nums_count_copy[num + diff] == 0) nums_count_copy.erase(num + diff);
        }
      }
      if (this_is_the_diff)
        return origin_vec;
      origin_vec.clear();
    }
    return {};
  }
};

int main(void) {
  vector<int> test_vec{2, 10, 6, 4, 8, 12};
  Solution sln;
  sln.recoverArray(test_vec);
  test_vec = {1, 1, 3, 3};
  sln.recoverArray(test_vec);
  test_vec = {5, 435};
  sln.recoverArray(test_vec);
  return 0;
}