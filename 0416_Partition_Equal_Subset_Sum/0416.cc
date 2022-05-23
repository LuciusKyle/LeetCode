
#include <map>
#include <numeric>
#include <unordered_map>
#include <vector>

using std::map;
using std::unordered_map;
using std::vector;

class Solution {
 public:
  bool canPartition(const vector<int>& nums) {
    const int sum = std::accumulate(nums.cbegin(), nums.cend(), 0);
    const int target = sum / 2;
    if (target * 2 != sum) return false;

    answer_cache_.assign(nums.size(), unordered_map<int, bool>());
    // vector<unordered_map<int, bool>>answer_cache(nums.size());
    return canPartition(nums, 0, target);
  }

 private:
  bool canPartition(const vector<int>& nums, const size_t cur_index, const int target) {
    if (answer_cache_[cur_index].count(target)) return answer_cache_[cur_index].at(target);
    if (cur_index == nums.size() - 1)
      return target == 0 || target == nums.back();
    if (target == 0)
      return true;
    if (target < 0) {
      answer_cache_[cur_index].insert({target, false});
      return false;
    }
    bool result = canPartition(nums, cur_index + 1, target) || canPartition(nums, cur_index + 1, target - nums[cur_index]);
    answer_cache_[cur_index].insert({target, result});
    return result;
  }
  
  bool canPartition(const vector<int>& nums, const size_t cur_index, const int target, vector<unordered_map<int, bool>>& answer_cache) {
    if (answer_cache[cur_index].count(target)) return answer_cache[cur_index].at(target);
    if (cur_index == nums.size() - 1)
      return target == 0 || target == nums.back();
    if (target == 0)
      return true;
    if (target < 0) {
      answer_cache[cur_index].insert({target, false});
      return false;
    }
    bool result = canPartition(nums, cur_index + 1, target, answer_cache) || canPartition(nums, cur_index + 1, target - nums[cur_index], answer_cache);
    answer_cache[cur_index].insert({target, result});
    return result;
  }

  vector<unordered_map<int, bool>> answer_cache_;
};

int main(void) {
  vector<int> test_vec{100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
  Solution sln;
  bool result = sln.canPartition(test_vec);
  test_vec = {2, 2, 3, 5};
  result = sln.canPartition(test_vec);
  return 0;
}

