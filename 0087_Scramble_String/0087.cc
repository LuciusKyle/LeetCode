
#include <immintrin.h>
#include <string.h>

#include <iostream>
#include <map>
#include <string>

using std::string;

class Solution {
 public:
  bool isScramble(const string s1, const string s2) {
    return isScramble(s1.c_str(), s2.c_str(), 0, 0, s1.size());
  }

 private:
   bool isScramble(const char* s1, const char* s2, const int start1, const int start2, const int len) {
    if (len == 1)
      return s1[start1] == s2[start2];
    if (result_cache_.count(start1) != 0 && result_cache_.at(start1).count(start2) != 0 && result_cache_.at(start1).at(start2).count(len) != 0)
      return result_cache_.at(start1).at(start2).at(len);
    char dict_s1_from_left[26] = {0}, dict_s2_from_left[26] = {0}, dict_s2_from_right[26] = {0};
    for (int i = 0; i < len - 1; ++i) {
      ++dict_s1_from_left[s1[i + start1] - 'a'];
      ++dict_s2_from_left[s2[i + start2] - 'a'];
      ++dict_s2_from_right[s2[len - 1 - i + start2] - 'a'];
      if (0 == memcmp(dict_s1_from_left, dict_s2_from_left, sizeof(dict_s1_from_left)) && isScramble(s1, s2, start1, start2, i + 1) && isScramble(s1, s2, start1 + i + 1, start2 + i + 1, len - 1 - i)) {
        result_cache_[start1][start2][len] = 1;
        return true;
      }
      if (0 == memcmp(dict_s1_from_left, dict_s2_from_right, sizeof(dict_s1_from_left)) && isScramble(s1, s2, start1, start2 + len - 1 - i, i + 1) && isScramble(s1, s2, start1 + i + 1, start2, len - 1 - i)) {
        result_cache_[start1][start2][len] = 1;
        return true;
      }
    }
    result_cache_[start1][start2][len] = 0;
    return false;
  }

  std::map<int, std::map<int, std::map<int, int>>> result_cache_;
};

int main(int argc, char* argv[]) {
  Solution sln;
  const string str1 = argc < 3 ? "eebaacbcbcadaaedceaaacadccd" : argv[1];
  const string str2 = argc < 3 ? "eadcaacabaddaceacbceaabeccd" : argv[2];
  bool result = sln.isScramble(str1, str2);
  std::cout << (result ? string("true") : string("false")) << std::endl;
}
