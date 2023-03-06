
#include <vector>

using std::vector;

class Solution {
 public:
  int findKthPositive(const vector<int>& arr, const int k) {
    int curr_num = 0, missed_count = 0;
    for (int i = 0; i < arr.size(); ++i) {
      missed_count += (arr[i] - curr_num - 1);
      curr_num = arr[i];
      if (k <= missed_count)
        return curr_num - (missed_count - k) - 1;
    }
    return curr_num + (k - missed_count);
  }
};
