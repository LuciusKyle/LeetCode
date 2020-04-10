#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  vector<string> findRelativeRanks(vector<int>& nums) {
    vector<int> indexes(nums.size());
    for (int i = 0; i < nums.size(); ++i) indexes[i] = i;
    std::sort(indexes.begin(), indexes.end(), [&nums](int a, int b) -> bool { return nums[a] > nums[b]; });
    vector<string> rtn(nums.size());
    rtn[indexes[0]] = "Gold Medal";
    if (1 < rtn.size()) rtn[indexes[1]] = "Silver Medal";
    if (2 < rtn.size()) rtn[indexes[2]] = "Bronze Medal";
    for (int i = 3; i < rtn.size(); ++i) rtn[indexes[i]] = std::to_string(i + 1);
    return rtn;
  }
};