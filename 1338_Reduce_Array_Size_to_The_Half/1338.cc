
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
    // vector<int> nums_count(100001, 0); // stack or heap? pick one!
    int nums_count[100001] = {0};  // stack or heap? pick one!
    for (const int num : arr) ++nums_count[num];
    vector<int> active_nums_count;
    active_nums_count.reserve(arr.size());
    for (const int num : nums_count)
      if (num) active_nums_count.push_back(num);
    std::sort(active_nums_count.rbegin(), active_nums_count.rend());
    for (int i = 0, count = 0, target_size = arr.size() / 2; i < active_nums_count.size(); ++i) {
      count += active_nums_count[i];
      if (target_size <= count) return i + 1;
    }
    return arr.size();
  }
};