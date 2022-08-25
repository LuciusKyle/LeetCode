
#include <array>
#include <string>

using std::array;
using std::string;

class Solution {
 public:
  bool canConstruct(const string ransomNote, const string magazine) {
    int magazine_count[26] = {0};
    for (const char ch : magazine) ++magazine_count[ch - 'a'];
    int ransomNote_count[26] = {0};
    for (const char ch : ransomNote) ++ransomNote_count[ch - 'a'];
    for (int i = 0; i < std::end(ransomNote_count) - std::begin(ransomNote_count); ++i)
      if (ransomNote_count[i] != 0 && ransomNote_count[i] < magazine_count[i]) return false;

    return true;
  }
};