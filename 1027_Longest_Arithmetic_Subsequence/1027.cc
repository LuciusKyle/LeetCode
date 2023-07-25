
#include <set>
#include <unordered_set>
#include <vector>

using std::vector;

class Solution {
 public:
  int longestArithSeqLength(vector<int>& nums) {
    std::set<int> all_possible_diffs;
    all_possible_diffs.insert(0);
    const int len = nums.size();
    for (int i = 0; i < len - 1; ++i) {
      for (int j = i + 1; j < len; ++j) {
        all_possible_diffs.insert(nums[j] - nums[i]);
      }
    }
    vector<int> dict(1001, -1);
    vector<int> curr_longest_seq(len, -1);
    int max_length = 0;
    for (auto iter = all_possible_diffs.cbegin(); iter != all_possible_diffs.cend(); ++iter) {
      const int diff = *iter;
      dict.assign(1001, -1);
      curr_longest_seq.assign(len, -1);
      for (int i = len - 1; 0 <= i; --i) {
        const int next_number = nums[i] + diff;
        curr_longest_seq[i] = (0 <= next_number && next_number <= 1000 && dict[next_number] != -1) ? curr_longest_seq[dict[next_number]] + 1 : 1;
        max_length = std::max(curr_longest_seq[i], max_length);
        dict[nums[i]] = i;
      }
    }
    return max_length;
  }
};
