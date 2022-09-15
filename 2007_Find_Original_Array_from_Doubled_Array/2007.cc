
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> findOriginalArray(vector<int>& changed) {
    if (changed.size() % 2 == 1) return {};
    vector<int> nums_counter(100002, 0);
    for (const int num : changed)
      ++nums_counter[num];
    vector<int> origin_vec;
    if (nums_counter[0] % 2 == 1)
      return {};
    else
      origin_vec.assign(nums_counter[0] / 2, 0);
    for (int i = 1; i < 50001; ++i) {
      while (nums_counter[i] != 0) {
        if (nums_counter[i * 2] == 0) return {};
        origin_vec.push_back(i);
        --nums_counter[i];
        --nums_counter[i * 2];
      }
    }
    if (origin_vec.size() == changed.size() / 2)
      return origin_vec;
    else
      return {};
  }
};