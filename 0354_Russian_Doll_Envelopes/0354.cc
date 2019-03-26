
#include <limits.h>
#include <algorithm>
#include <map>
#include <vector>

using std::pair;
using std::vector;

class Solution {
 public:
  int maxEnvelopes(vector<pair<int, int>> &envelopes) {
    if (envelopes.empty()) return 0;
    std::sort(envelopes.begin(), envelopes.end(),
              [](pair<int, int> &left, pair<int, int> &right) -> bool {
                if (right.first < left.first)
                  return true;
                else if (left.first < right.first)
                  return false;
                else
                  return right.second < left.second;
              });
    vector<int> result(envelopes.size(), 1);
    int rtn = 1;
    for (size_t i = 1; i < result.size(); ++i)
      for (size_t ii = 0; ii < i; ++ii)
        if (envelopes[i].first < envelopes[ii].first &&
            envelopes[i].second < envelopes[ii].second)
          if (result[i] < result[ii] + 1) {
            result[i] = result[ii] + 1;
            rtn = rtn < result[i] ? result[i] : rtn;
          }
    return rtn;
    return 0;
  }
};

int main(void) {
  Solution sln;

  return 0;
}
