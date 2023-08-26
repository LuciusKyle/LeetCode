
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
 public:
  int findLongestChain(vector<vector<int>>& pairs) {
    const int length = pairs.size();
    std::sort(pairs.begin(), pairs.end(), [](const vector<int>& _x, const vector<int>& _y) -> bool {
      return _x[0] == _y[0] ? _x[1] < _y[1] : _x[0] < _y[0];
    });
    vector<int> results(pairs.size(), 1);
    int max_len = 1;
    for (int len = 1; len < length; ++len) {
      const vector<int>& curr_p = pairs[len];
      int temp_max = 1;
      for (int i = 0; i < len; ++i)
        if (pairs[i][1] < curr_p[0])
          temp_max = std::max(temp_max, results[i] + 1);
      results[len] = temp_max;
      max_len = std::max(max_len, temp_max);
    }
    return max_len;
  }
};
