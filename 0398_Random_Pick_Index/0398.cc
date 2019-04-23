
#include <random>
#include <unordered_map>
#include <vector>

using std::vector;

// std::uniform_int_distribution will reduce performance, but this solution is ok.
class Solution {
 public:
  Solution(const vector<int> nums) {
    for (size_t i = 0; i < nums.size(); ++i)
      if (data_.count(nums[i]) == 0)
        data_.insert({nums[i], vector<size_t>(1, i)});
      else
        data_.at(nums[i]).push_back(i);
  }

  int pick(int target) {
    const auto &vec = data_.at(target);
    return int(vec[dist(rd) % vec.size()]);
  }

 private:
  std::unordered_map<int, vector<size_t>> data_;
  std::random_device rd;
  std::uniform_int_distribution<size_t> dist;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

int main(void ) {
  Solution sln({1,2,3,3,3});;
  sln.pick(3);

  return 0;
}