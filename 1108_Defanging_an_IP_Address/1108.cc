
#include <string>

using std::string;

class Solution {
 public:
  string defangIPaddr(string address) {
    string result;
    result.reserve(23);
    for (const char ch : address)
      if (ch == '.')
        result.append("[.]");
      else
        result.push_back(ch);
    return result;
  }
};