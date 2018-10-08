

#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> rtn;
#if 201402L < __cplusplus
    vector dup_val(nums.size(), true);
#else
    vector<bool> dup_val(nums.size(), true);
#endif
    vector<int> buffer;
    combineWithDup(rtn, buffer, nums, 0, dup_val);
    return rtn;
  }

 private:
  void combineWithDup(vector<vector<int>> &rtn, vector<int> &buffer, const vector<int> &set, const size_t cur_index, vector<bool> &dup_val) {
    if (cur_index == set.size()) {
      rtn.push_back(buffer);
      return;
    }
    if (dup_val[cur_index]) {
      buffer.push_back(set[cur_index]);
      combineWithDup(rtn, buffer, set, cur_index + 1, dup_val);
      buffer.pop_back();
      for (size_t i = cur_index + 1; i < set.size(); ++i)
        if (set[i] == set[cur_index])
          dup_val[i] = false;
        else
          dup_val[i] = true;
    }
    combineWithDup(rtn, buffer, set, cur_index + 1, dup_val);
  }
};

int main(void) {
  Solution sln;
  vector<int> test_sample{1, 2, 2};
  auto rtn = sln.subsetsWithDup(test_sample);
  return 0;
}
