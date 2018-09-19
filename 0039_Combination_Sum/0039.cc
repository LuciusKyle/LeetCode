
#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> rtn;
    if (!candidates.empty()) {
      vector<int> answer_buffer;
      answer_buffer.reserve(candidates[0] * target);
      sub_combinationSum(candidates, target, candidates.size() - 1,
                         answer_buffer, rtn);
    }
    return rtn;
  }

 private:
  int sub_combinationSum(const vector<int>& candidates, const int target,
                         const size_t current_index, vector<int>& answer,
                         vector<vector<int>>& rtn) {
    if (current_index == 0) {
      if (target % candidates[0] != 0)
        return -1;
      else {
        const int count = target / candidates[0];
        for (int i = 0; i < count; ++i) answer.push_back(candidates[0]);
        rtn.push_back(answer);
        for (int i = 0; i < count; ++i) answer.pop_back();
        return count;
      }
    }
    int count = target / candidates[current_index] + 1;
    for (int i = 0; i < count; ++i) {
      for (int ii = 0; ii < i; ++ii)
        answer.push_back(candidates[current_index]);
      if (-1 != sub_combinationSum(candidates,
                                   target - i * candidates[current_index],
                                   current_index - 1, answer, rtn)) {
        // return target / candidates[current_index];

        // can't return function here. continue seearching for all possible
        // answer.
      } else {
      }
      // return -1;

      for (int ii = 0; ii < i; ++ii) answer.pop_back();
    }
    return -1;
  }
};



int main(void) {
  Solution sln;
  vector<int> question_vec{2, 3, 5};
  auto rtn = sln.combinationSum(question_vec, 8);

  return 0;
}
