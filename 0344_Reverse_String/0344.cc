
#include <string>

using std::string;

class Solution {
 public:
  string reverseString(string s) { return {s.crbegin(), s.crend()}; }
};