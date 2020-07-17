
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    if (nums.size() < 2) return nums;
    std::sort(nums.begin(), nums.end()); //, [](int a, int b) -> bool { return b < a; }
    vector <int> result(nums.size(), -1);
    vector <vector<int>> result_vec(nums.size());
    for (int i = 0;i < result_vec.size();++i)
      result_vec[i].push_back(nums[i]);

    int rtn = 0;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] % nums[j] == 0) {
          if (result[i] < result[j] + 1) {
            result[i] = result[j] + 1;
            rtn = rtn < result[i] ? result[i] : rtn;
          }
        }
      }
    }
    // return rtn;
  }
};

