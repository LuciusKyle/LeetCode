
#include <assert.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) return "";
    size_t min_size = SIZE_MAX;
    for (const auto& str : strs)
      if (str.size() < min_size) min_size = str.size();
    if (min_size == 0) return "";
    size_t same_pre_count = 0;
    for (size_t ii = 0; ii < min_size; ++ii) {
      const int first_ch = strs[0][ii];
      for (size_t i = 1; i < strs.size(); ++i)
        if (strs[i][ii] != first_ch) break;
      same_pre_count++;
    }
    return string(strs[0].cbegin(), strs[0].cbegin() + same_pre_count);
  }
};

int main(void) {
  Solution sln;
  vector<string> param{"flower","flow","flight"};
  auto rtn = sln.longestCommonPrefix(param);
  assert(rtn == "abc");

  return 0;
}
