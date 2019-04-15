
#include <array>
#include <string>

using std::string;

class Solution {
 public:
  bool isAnagram(const string s, const string t) {
    if (s.size() != t.size()) return false;
    std::array<size_t, 0x100> arr_of_s{0};
    std::array<size_t, 0x100> arr_of_t{0};

    for (size_t i = 0; i < s.size(); ++i) {
      ++arr_of_s[s[i]];
      ++arr_of_t[t[i]];
    }
    for (size_t i = 0; i < 0x100; ++i)
      if (arr_of_s[i] != arr_of_t[i]) return false;
    return true;
  }
};

int main(void) {
  Solution sln;
  return 0;
}