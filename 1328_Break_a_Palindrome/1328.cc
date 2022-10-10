#include <string>

using std::string;

class Solution {
 public:
  string breakPalindrome(string palindrome) {
    const int length = palindrome.size();
    if (length == 1) return "";
    bool all_a = true;
    for (int i = 0; i < length / 2; ++i)
      if (palindrome[i] != 'a') {
        palindrome[i] = 'a';
        all_a = false;
        break;
      }
    if (!all_a) return palindrome;
    for (int i = (length % 2 == 0 ? length / 2 : (length / 2 + 1)); i < length; ++i)
      if (palindrome[i] != 'a') {
        palindrome[i] = 'a';
        all_a = false;
        break;
      }
    if (all_a) palindrome[length - 1] = 'b';
    return palindrome;
  }
};