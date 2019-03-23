
#include <assert.h>
#include <string>

using std::string;

class Solution {
 public:
  bool isSubsequence(const string s, const string t) {
    size_t s_index = 0;
    for (size_t i = 0; i < t.size(); ++i)
      if (s[s_index] == t[i]) {
        ++s_index;
        if (s_index == s.size()) return true;
      }
    return s_index == s.size();
  }
};

int main(void) {
  Solution sln;
  assert(!sln.isSubsequence("axc", "ahbgdc"));
  assert(sln.isSubsequence("abc", "ahbgdc"));
  return 0;
}
