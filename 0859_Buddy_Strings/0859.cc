
#include <string>

using std::string;

class Solution {
 public:
  bool buddyStrings(const string s, const string goal) {
    const int len = s.size();
    if (goal.size() != len) return false;
    int diff_index[] = {-1, -1}, diff_count = 0, max_duplication = 0;
    for (int i = 0, dict[26] = {0}; i < len; ++i) {
      if (s[i] != goal[i]) {
        if (diff_count == 2) return false;
        diff_index[diff_count++] = i;
      }
      ++dict[s[i] - 'a'];
      max_duplication = std::max(dict[s[i] - 'a'], max_duplication);
    }
    if (diff_count == 0)
      return 1 < max_duplication;
    else if (diff_count != 2)
      return false;
    else
      return diff_index[0] != -1 && diff_index[1] != -1 && s[diff_index[0]] == goal[diff_index[1]] && s[diff_index[1]] == goal[diff_index[0]];
  }
};
