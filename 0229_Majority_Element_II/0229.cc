
#include <map>
#include <vector>

using std::map;
using std::vector;

class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    vector<int> rtn;
    map<int, int> val_freq_map;
    for (const int val : nums)
      ++val_freq_map[val];
    for (auto iter = val_freq_map.cbegin(); iter != val_freq_map.cend(); ++iter)
      if (iter->second > nums.size() / 3) rtn.push_back(iter->first);
    return rtn;
  }
};
