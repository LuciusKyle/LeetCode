
#include <string>

using std::string;

class Solution {
 public:
  bool validPalindrome(const string s) {
    int l_index = 0, r_index = s.size() - 1;
    while (l_index < r_index) {
      if (s[l_index] != s[r_index])
        return validPalindrome(s, l_index, r_index - 1) || validPalindrome(s, l_index + 1, r_index);
      ++l_index;
      --r_index;
    }
    return true;
  }

 private:
  bool validPalindrome(const string &s, int l_index, int r_index) {
    while (l_index < r_index)
      if (s[l_index++] != s[r_index--]) return false;
    return true;
  }
};

int main(int argc, char *argv[]) {
  const string test_str = argc > 1 ? argv[1] : "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
  Solution sln;
  sln.validPalindrome(test_str);
  return 0;
}
