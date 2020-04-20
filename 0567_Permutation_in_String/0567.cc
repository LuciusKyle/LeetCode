
#include <string>

using std::string;

class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    int s2_index = 0;
    for (int i = 0; i < s1.size(); ++i) {
      while (s2_index < s2.size() && s1[i] != s2[s2_index]);
      for (; s2_index < s2.size(); ++s2_index) {
        if (s1[i] == s2[s2_index])
          break;
      }
      if (s2.size() <= s2_index) return false;
    }
  }
};
