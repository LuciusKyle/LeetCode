
#include <string.h>

#include <string>
#include <type_traits>

using std::string;

class Solution {
 public:
  bool checkInclusion(const string s1, const string s2) {
    if (s2.size() < s1.size()) return false;
    const int length1 = s1.size();
    short dict_s2[26] = {0}, dict_s1[26] = {0};
    for (const char ch : s1) ++dict_s1[ch - 'a'];
    for (int i = 0; i < length1; ++i)
      ++dict_s2[s2[i] - 'a'];
    if (memcmp(dict_s1, dict_s2, sizeof(std::remove_reference_t<decltype(*dict_s1)>) * (std::end(dict_s1) - std::begin(dict_s1))) == 0) return true;
    for (int i = length1; i < s2.size(); ++i) {
      ++dict_s2[s2[i] - 'a'];
      --dict_s2[s2[i - length1] - 'a'];
      if (memcmp(dict_s1, dict_s2, sizeof(std::remove_reference_t<decltype(*dict_s1)>) * (std::end(dict_s1) - std::begin(dict_s1))) == 0) return true;
    }
    return false;
  }
};
