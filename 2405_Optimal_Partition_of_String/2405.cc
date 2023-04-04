
#include <string>

using std::string;

class Solution {
 public:
  int partitionString(string s) {
    int ch_dict = 0, result = 0;
    for (const char ch : s) {
      if ((1 << (ch - 'a')) & ch_dict) {
        ++result;
        ch_dict = 0;
      }
      ch_dict ^= (1 << (ch - 'a'));
    }
    return result;
  }
};