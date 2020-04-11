
#include <assert.h>

#include <vector>

using std::vector;

class Solution {
 public:
  int combinationSum4(const vector<int>& candidates, int target) {
    vector<vector<int>> rtn;
    vector<int> answer_buffer;
    combinationSum4(candidates, target, rtn, answer_buffer);
    return rtn.size();
  }

 private:
  void combinationSum4(const vector<int>& candidates, const int target, vector<vector<int>>& rtn, vector<int> answer_buffer) {
    for (const int val : candidates) {
      if (0 < target - val) {
        answer_buffer.push_back(val);
        combinationSum4(candidates, target - val, rtn, answer_buffer);
        answer_buffer.pop_back();
        continue;
      }
      if (target - val == 0) {
        answer_buffer.push_back(val);
        rtn.push_back(answer_buffer);
        answer_buffer.pop_back();
      }
    }
  }
};
