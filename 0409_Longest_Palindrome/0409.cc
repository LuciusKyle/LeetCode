
#include <string>

using std::string;

class Solution {
 public:
  int longestPalindrome(const string s) {
    size_t letters_count[0x100] = {0};
    for (const auto ch : s) ++letters_count[ch];
    bool extra_ch = false;
    size_t rtn = 0;
    for(const size_t count:letters_count) 
      if (count % 2) {
        extra_ch = true;
        rtn += (count - 1);
      } else {
        rtn += count;
      }
    return static_cast<int>(extra_ch ? rtn + 1 : rtn);
  }
};

int main(void) {
  Solution sln;

  return 0;
}