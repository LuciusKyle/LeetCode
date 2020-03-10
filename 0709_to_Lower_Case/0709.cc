
#include <string>

using std::string;

class Solution {
 public:
  string toLowerCase(string str) {
    for (int i = 0; i < str.size(); ++i)
      if ('A' <= str[i] && str[i] <= 'Z') str[i] += 0x20;
    return str;
  }
};