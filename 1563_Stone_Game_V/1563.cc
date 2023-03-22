
#include <limits.h>

#include <vector>

using std::vector;

class Solution {
 public:
  int stoneGameV(const vector<int>& stoneValue) {
    prefix_sum_.reserve(stoneValue.size() + 1);
    prefix_sum_.push_back(0);
    for (const int val : stoneValue)
      prefix_sum_.push_back(val + prefix_sum_.back());
    dp_.assign(stoneValue.size(), vector<int>(stoneValue.size() + 1, -1));
    return stoneGameV(stoneValue, 0, stoneValue.size());
  }

 private:
  vector<int> prefix_sum_;
  vector<vector<int>> dp_;
  int stoneGameV(const vector<int>& stoneValue, int start, int end) {
    if (dp_[start][end] != -1) return dp_[start][end];
    if (start + 2 == end) {
      dp_[start][end] = std::min(stoneValue[start], stoneValue[end - 1]);
      return dp_[start][end];
    }
    if (start + 1 == end) {
      dp_[start][end] = 0;
      return 0;
    }
    int final_score = 0, max_score = INT_MIN;
    for (int cut_pos = start + 1; cut_pos < end; ++cut_pos) {
      const int left_sum = prefix_sum_[cut_pos] - prefix_sum_[start], right_sum = prefix_sum_[end] - prefix_sum_[cut_pos];
      if (left_sum < right_sum)
        final_score = left_sum + stoneGameV(stoneValue, start, cut_pos);
      else if (right_sum < left_sum)
        final_score = right_sum + stoneGameV(stoneValue, cut_pos, end);
      else
        final_score = left_sum + std::max(stoneGameV(stoneValue, start, cut_pos), stoneGameV(stoneValue, cut_pos, end));
      if (max_score < final_score) max_score = final_score;
    }
    dp_[start][end] = max_score;
    return max_score;
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  vector<int> test_vec{1, 1, 2};
  int result = sln.stoneGameV(test_vec);
  return 0;
}