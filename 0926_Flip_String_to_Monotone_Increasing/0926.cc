
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int minFlipsMonoIncr(const string s) {
    int zeros = 0;
    for (const char ch : s)
      if (ch == '0') ++zeros;
    int min_flip = std::min(zeros, int(s.size()) - zeros);
    for (int i = 0, ones = 0; i < s.size(); ++i) {
      if (s[i] == '1') ++ones;
      const int curr_flip = ones + (zeros - (i + 1 - ones));
      if (curr_flip < min_flip) min_flip = curr_flip;
    }
    return min_flip;
  }
};
