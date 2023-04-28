
#include <limits.h>

#include <vector>

using std::vector;

class Solution {
 public:
  bool canMakeArithmeticProgression(const vector<int>& arr) {
    int val = arr[0], min_diff = INT_MAX, min_val = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
      min_diff = std::min(min_diff, std::abs(arr[i] - val));
      min_val = std::min(min_val, arr[i]);
    }
    if (min_diff == 0) {
      for (const int num : arr)
        if (num != val) return false;
      return true;
    }
    vector<int> num_dict(arr.size(), 0);
    for (int i = 0; i < arr.size(); ++i) {
      const int correct_pos = (arr[i] - min_val) / min_diff;
      if ((arr[i] - min_val) % min_diff != 0) return false;
      if (arr.size() <= correct_pos) return false;
      if (num_dict[correct_pos] == 1) return false;
      num_dict[correct_pos] = 1;
    }
    return true;
  }
};
