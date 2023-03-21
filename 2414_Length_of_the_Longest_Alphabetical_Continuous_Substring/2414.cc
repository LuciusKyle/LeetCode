
#include <string>

using std::string;

class Solution {
 public:
  int longestContinuousSubstring(string s) {
    int answer = 1;
    for (int i = 1, pre_contiguous_count = 1; i < s.size(); ++i)
      if (s[i] - 1 == s[i - 1]) {
        ++pre_contiguous_count;
        if (answer < pre_contiguous_count) answer = pre_contiguous_count;
      } else
        pre_contiguous_count = 1;
    return answer;
  }
};