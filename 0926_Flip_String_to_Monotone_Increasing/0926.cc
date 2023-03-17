
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int minFlipsMonoIncr(const string s) {
    vector<int> count_zeros_and_ones;
    count_zeros_and_ones.reserve(s.size() * 2);
    int zeros = 0, ones = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '0')
        ++zeros;
      else
        ++ones;
      count_zeros_and_ones.push_back(zeros);
      count_zeros_and_ones.push_back(ones);
    }
    if (zeros == 0 || ones == 0) return 0;
    int min_flip = std::min(zeros, ones);
    for (int i = 0; i < s.size(); ++i) {
      min_flip = std::min(count_zeros_and_ones[2 * i + 1] + (zeros - count_zeros_and_ones[2 * i]), min_flip);
    }
    return min_flip;
  }
};
