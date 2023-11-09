
#include <string>
#include <vector>

using std::string;
using std::vector;

constexpr int kModulo = 1'000'000'000 + 7;

class Solution {
 public:
  int countHomogenous(string s) {
    int answer = 0, curr_count = 1;
    char pre_ch = s.front();
    for (int i = 1, repeation_count = 1; i < s.size(); ++i) {
      if (s[i] != s[i - 1]) {
        answer += curr_count;
        answer %= kModulo;
        curr_count = 1;
        repeation_count = 1;
      } else {
        curr_count += ++repeation_count;
        curr_count %= kModulo;
      }
    }
    return (answer + curr_count) % kModulo;
  }
};
