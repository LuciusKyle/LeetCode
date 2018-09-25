
#include <assert.h>
#include <string>

using std::string;

class Solution {
 public:
  int lengthOfLastWord(const string s) const {
    int rtn = 0;
    bool start_count = false;
    for (auto r_iter = s.crbegin(); r_iter != s.crend(); ++r_iter)
      if (start_count)
        if (*r_iter != ' ')
          ++rtn;
        else
          return rtn;
      else if (*r_iter != ' ') {
        ++rtn;
        start_count = true;
      }
    return rtn;
  }
};

int main(void) {
  Solution sln;
  assert(sln.lengthOfLastWord("Hello World") == 5);
  assert(sln.lengthOfLastWord("World") == 5);
  assert(sln.lengthOfLastWord("a") == 1);
  assert(sln.lengthOfLastWord("") == 0);
  assert(sln.lengthOfLastWord(" ") == 0);
  assert(sln.lengthOfLastWord("abc   ") == 3);
  assert(sln.lengthOfLastWord("asdf abc   ") == 3);
  return 0;
}