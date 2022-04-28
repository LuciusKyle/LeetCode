
#include <immintrin.h>
#include <string.h>

#include <iostream>
#include <string>

using std::string;

class Solution {
 public:
  bool isScramble(const string s1, const string s2) {
    return (isScramble(s1.c_str(), s2.c_str()));
  }

 private:
  bool isScramble(const char* s1, const char* s2) {
    return isScramble(s1, s2, strlen(s1));
  }

  bool isScramble(const char* s1, const char* s2, const int len) {
    if (len == 1) return s1[0] == s2[0];
    // char dict_s1_from_left[32] = {0}, dict_s2_from_left[32] = {0}, dict_s2_from_right[32] = {0};
    char dict_s1_from_left[26] = {0}, dict_s2_from_left[26] = {0}, dict_s2_from_right[26] = {0};
    for (int i = 0; i < len - 1; ++i) {
      ++dict_s1_from_left[s1[i] - 'a'];
      ++dict_s2_from_left[s2[i] - 'a'];
      ++dict_s2_from_right[s2[len - 1 - i] - 'a'];
      // if (0xffffffffu == _mm256_movemask_epi8(_mm256_cmpeq_epi32(*reinterpret_cast<__m256i*>(dict_s1_from_left), *reinterpret_cast<__m256i*>(dict_s2_from_left))) && isScramble(s1, s2, i + 1) && isScramble(s1 + i + 1, s2 + i + 1, len - 1 - i))
      //   return true;
      // if (0xffffffffu == _mm256_movemask_epi8(_mm256_cmpeq_epi32(*reinterpret_cast<__m256i*>(dict_s1_from_left), *reinterpret_cast<__m256i*>(dict_s2_from_right))) && isScramble(s1, s2 + len - 1 - i, i + 1) && isScramble(s1 + i + 1, s2, len - 1 - i))
      //   return true;

      if (0 == memcmp(dict_s1_from_left, dict_s2_from_left, sizeof(dict_s1_from_left)) && isScramble(s1, s2, i + 1) && isScramble(s1 + i + 1, s2 + i + 1, len - 1 - i))
        return true;
      if (0 == memcmp(dict_s1_from_left, dict_s2_from_right, sizeof(dict_s1_from_left)) && isScramble(s1, s2 + len - 1 - i, i + 1) && isScramble(s1 + i + 1, s2, len - 1 - i))
        return true;
    }
    return false;
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  const string str1 = argc < 3 ? "eebaacbcbcadaaedceaaacadccd" : argv[1];
  const string str2 = argc < 3 ? "eadcaacabaddaceacbceaabeccd" : argv[2];
  bool result = sln.isScramble(str1, str2);
  std::cout << (result ? string("true") : string("false")) << std::endl;
}
