
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> rtn;
    vector<int> answer_buffer;
    answer_buffer.reserve(candidates.size());
    std::sort(candidates.begin(), candidates.end());
    sub_combinationSum2(rtn, candidates, answer_buffer, target,
                        candidates.back(), true);
    return rtn;
  }

 private:
  void sub_combinationSum2(vector<vector<int>>& rtn, vector<int>& candidates,
                           vector<int>& answer, const int target,
                           const int pre_val, const bool used_val) {
    if (target == 0 && !answer.empty()) {
      rtn.push_back(answer);
      return;
    }
    if (target < 0 || candidates.empty()) {
      return;
    }

    const int num = candidates.back();
    candidates.pop_back();
    sub_combinationSum2(rtn, candidates, answer, target, num, false);

    if (pre_val != num || used_val) {
      answer.push_back(num);
      sub_combinationSum2(rtn, candidates, answer, target - num, num, true);
      answer.pop_back();
    }
    candidates.push_back(num);
  }
};

int main(void) {
  Solution sln;

  vector<int> question{10, 1, 2, 7, 6, 1, 5};
  auto rtn = sln.combinationSum2(question, 8);
  return 0;
}
