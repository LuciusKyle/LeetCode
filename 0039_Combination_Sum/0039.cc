
#include <vector>
#include <algorithm>
#include <set>

using std::vector;


class Solution {
 public:
  vector<vector<int>> combinationSum(const vector<int>& candidates, int target) {
    vector<vector<int>> rtn;
    vector<int> answer_buffer;
    combinationSum(candidates, target, 0, rtn, answer_buffer);
    return rtn;
  }

 private:
  void combinationSum(const vector<int>& candidates, const int target, const size_t start_index, vector<vector<int>>& rtn, vector<int> answer_buffer) {
    for (size_t i = start_index; i < candidates.size(); ++i) {
      if (0 < target - candidates[i]) {
        answer_buffer.push_back(candidates[i]);
        combinationSum(candidates, target - candidates[i], i, rtn, answer_buffer);
        answer_buffer.pop_back();
        continue;
      }
      if (target - candidates[i] == 0) {
        answer_buffer.push_back(candidates[i]);
        rtn.push_back(answer_buffer);
        answer_buffer.pop_back();
      }
    }
  }
};


int main(void) {
  Solution sln;
  vector<int> question_vec{2, 3, 5};
  auto rtn = sln.combinationSum(question_vec, 8);

  return 0;
}
