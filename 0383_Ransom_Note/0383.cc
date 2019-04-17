
#include <array>
#include <string>

using std::array;
using std::string;

class Solution {
 public:
  bool canConstruct(const string ransomNote, const string magazine) {
    array<size_t, 26> letters_count{0};
    for (const char ch : magazine) ++letters_count[ch - 'a'];
    for (const char ch : ransomNote)
      if (letters_count[ch - 'a'] == 0)
        return false;
      else
        --letters_count[ch - 'a'];
    return true;
  }
};