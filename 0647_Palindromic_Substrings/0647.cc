
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int countSubstrings(const string s) {
    vector<vector<int>> answer_cache(s.size(), vector<int>(s.size(), 0));

    // length is 1:
    for (size_t i = 0; i < s.size(); ++i) answer_cache[i][i] = 1;
    int result = s.size();

    // length is 2:
    if (1 < s.size())
      for (size_t i = 0; i < s.size() - 1; ++i)
        if (s[i] == s[i + 1]) {
          ++result;
          answer_cache[i][i + 1] = 1;
        }

    // length is 3...s.size():
    for (size_t len = 3; len <= s.size(); ++len)
      for (size_t start_index = 0; start_index + len - 1 < s.size(); ++start_index)
        if (s[start_index] == s[start_index + len - 1] && answer_cache[start_index + 1][start_index + len - 2]) {
          ++result;
          answer_cache[start_index][start_index + len - 1] = 1;
        }

    return result;
  }
};