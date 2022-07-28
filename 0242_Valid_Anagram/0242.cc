
#include <memory.h>

#include <string>

using std::string;

class Solution {
 public:
  bool isAnagram(const string s, const string t) {
    if (s.size() != t.size()) return false;
    int dict_s[26] = {0}, dict_t[26] = {0};
    for (int i = 0; i < s.size(); ++i) {
      ++dict_s[s[i] - 'a'];
      ++dict_t[t[i] - 'a'];
    }
    return 0 == memcmp(dict_s, dict_t, 26 * sizeof(int));
  }
};

int main(void) {
  Solution sln;
  return 0;
}