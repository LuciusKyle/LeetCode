
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int numWays(vector<string>& words, string target) {
    const int candidate_length = words[0].size();
    vector<vector<int>> ch_count(candidate_length, vector<int>(26));
    for (int i = 0; i < words.size(); ++i) {
      for (int j = 0; j < candidate_length; ++j) {
        ++ch_count[j][words[i][j] - 'a'];
      }
    }
    vector<vector<int>> answer(candidate_length, vector<int>(target.size(), 0));
    answer[0][0] = ch_count[0][target[0] - 'a'];
    for (int i = 1, prefix_sum = 0; i < candidate_length; ++i)
      answer[i][0] = answer[i - 1][0] + ch_count[i][target[0] - 'a'];
    for (int i = 1; i < target.size(); ++i) {
      for (int j = i; j < candidate_length; ++j) {
        answer[j][i] = ch_count[j][target[i] - 'a'] * answer[j - 1][i - 1] + answer[j - 1][i];
      }
    }
    int result = 0;
    for (int i = target.size() - 1; i < candidate_length; ++i) {
      result += answer[i].back();
    }
    return result;
  }
};
