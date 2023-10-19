
#include <string>

using std::string;

class Solution {
 public:
  bool backspaceCompare(string s, string t) {
    int logical_index = 0;
    for (int real_index = 0; real_index < s.size(); ++real_index) {
      if (s[real_index] == '#') {
        logical_index = std::max(0, --logical_index);
      } else {
        s[logical_index++] = s[real_index];
      }
    }
    s.resize(logical_index);
    logical_index = 0;
    for (int real_index = 0; real_index < t.size(); ++real_index) {
      if (t[real_index] == '#') {
        logical_index = std::max(0, --logical_index);
      } else {
        t[logical_index++] = t[real_index];
      }
    }
    t.resize(logical_index);
    return s == t;
  }
};
