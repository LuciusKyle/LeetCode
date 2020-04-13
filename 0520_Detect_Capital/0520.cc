
#include <string>
#include <assert.h>

using std::string;

class Solution {
 public:
  // 41% beat.

  //bool detectCapitalUse(const string word) {
  //  // if (word.empty() || word.size() == 1) return true; // input will be non-empty.
  //  bool property = 'a' <= word[0];
  //  for (size_t i = 0; i < word.size(); ++i)
  //    if (('a' <= word[i]) != property)  // upper and lower changed.
  //      if (word[i] <= 'Z') return false;  // from lower to upper, return false.
  //      else { // from upper to lower.
  //        if (i != 1)
  //          return false;
  //        else
  //          for (i; i < word.size(); ++i)
  //            if (word[i] <= 'Z') return false;
  //      }
//
  //  return true;
  //}


  // 100% beat.
  bool detectCapitalUse(string word) {
    if (word[0] <= 'Z') { // first letter is upper.
      if (word.size() == 1) return true;
      if (word[1] <= 'Z') { // second letter is upper.
        for (size_t i = 2; i < word.size(); ++i) 
          if ('Z' < word[i]) return false;
        return true;
      } else { // second letter is lower.
        for (size_t i = 2; i < word.size(); ++i)
          if (word[i] < 'a') return false;
        return true;
      }
    } else { // first letter is lower.
      for (size_t i = 1; i < word.size(); ++i)
        if (word[i] < 'a') return false;
      return true;
    }
    return true;
  }
};

int main(void) {
  Solution sln;
  assert(sln.detectCapitalUse("ABC"));
  assert(sln.detectCapitalUse("abcdefg"));
  assert(sln.detectCapitalUse("Abcdefg"));
  assert(!sln.detectCapitalUse("abcDefg"));
  assert(!sln.detectCapitalUse("abcDefG"));
  assert(!sln.detectCapitalUse("ABCDEFg"));

  return 0;
}
