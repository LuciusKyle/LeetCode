
#include <string>

using std::string;

class Solution {
 public:
  char findTheDifference(const string s, const string t) {
    size_t dict_s[26] = {0};
    size_t dict_t[26] = {0};
    for (const char ch : s) ++dict_s[ch - 'a'];
    for (const char ch : t) ++dict_t[ch - 'a'];
    for (size_t i = 0; i < 26; ++i)
      if (dict_s[i] != dict_t[i]) return static_cast<char>(i + 'a');
    return '?';    
  }

 private:
  char moreGeneralFunction(const string s, const string t) {
    size_t dict_s[0x100] = {0};
    size_t dict_t[0x100] = {0};
    for (const char ch : s) ++dict_s[ch];
    for (const char ch : t) ++dict_t[ch];
    for (size_t i = 0; i < 0x100; ++i)
      if (dict_s[i] != dict_t[i]) return static_cast<char>(i);
    return '?';
  }
};

int main(void) {
  Solution sln;
  return 0;
}
