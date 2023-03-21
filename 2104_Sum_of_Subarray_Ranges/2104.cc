
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  long long subArrayRanges(vector<int>& nums) {
    long long answer = 0;
    vector<std::pair<int, int>> min_max_pair_vec;
    min_max_pair_vec.reserve(nums.size() - 1);
    for (int i = 1; i < nums.size(); ++i) {
      min_max_pair_vec.emplace_back(std::min(nums[i - 1], nums[i]), std::max(nums[i - 1], nums[i]));
      answer += min_max_pair_vec.back().second - min_max_pair_vec.back().first;
    }
    for (int i = 2; i < nums.size(); ++i)
      for (int j = i; j < nums.size(); ++j) {
        min_max_pair_vec[j - i].first = std::min(min_max_pair_vec[j - i].first, nums[j]);
        min_max_pair_vec[j - i].second = std::max(min_max_pair_vec[j - i].second, nums[j]);
        answer += min_max_pair_vec[j - i].second - min_max_pair_vec[j - i].first;
      }
    return answer;
  }
};
