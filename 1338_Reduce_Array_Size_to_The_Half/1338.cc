
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>

using std::map;
using std::unordered_map;
using std::vector;

class Solution {
 public:
  int minSetSize(vector<int>& arr) {
    vector<int> nums_count(100001, 0);
    for (const int num : arr) ++nums_count[num];
    std::sort(nums_count.rbegin(), nums_count.rend());
    for (int i = 0, count = 0, target_size = arr.size() / 2; i < 100000; ++i) {
      count += nums_count[i];
      if (target_size <= count) return i + 1;
    }
    return arr.size();
  }
};