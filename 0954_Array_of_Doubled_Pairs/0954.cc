
#include <vector>

using std::vector;

class Solution {
 public:
  bool canReorderDoubled(const vector<int>& arr) {
    vector<int> positive_num_counter(100001, 0), negative_num_counter(100001, 0);
    int zero_counter = 0;
    for (const int num : arr)
      if (num < 0)
        ++negative_num_counter[-1 * num];
      else if (0 < num)
        ++positive_num_counter[num];
      else
        ++zero_counter;
    if (zero_counter % 2 != 0) return false;
    int all_num_counter = zero_counter / 2;
    for (int i = 1; i < 50001; ++i) {
      while (positive_num_counter[i] != 0) {
        if (positive_num_counter[i * 2] == 0) return false;
        --positive_num_counter[i];
        --positive_num_counter[i * 2];
        ++all_num_counter;
      }
      while (negative_num_counter[i] != 0) {
        if (negative_num_counter[i * 2] == 0) return false;
        --negative_num_counter[i];
        --negative_num_counter[i * 2];
        ++all_num_counter;
      }
    }
    return all_num_counter == arr.size() / 2;
  }
};