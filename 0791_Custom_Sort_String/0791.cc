
#include <string>

using std::string;

class Solution {
 public:
  string customSortString(string S, string T) {
    int dict[26]{0};
    for (const char ch : T) ++dict[ch - 'a'];
    int cur_index = 0;
    for (const char ch : S)
      while (dict[ch - 'a']-- != 0) T[cur_index++] = ch;
    for (int i = 0; i < std::end(dict) - std::begin(dict); ++i)
      for (int j = 0; j < dict[i]; ++j) T[cur_index++] = i + 'a';
    return T;
  }
};

