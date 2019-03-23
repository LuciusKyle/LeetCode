
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int numDistinct(string s, string t) {
    int m = t.length(), n = s.length();
    vector<size_t> cur(m + 1, 0);
    cur[0] = 1;
    for (size_t j = 1; j <= n; j++) {
      size_t pre = 1;
      for (size_t i = 1; i <= m; i++) {
        size_t temp = cur[i];
        cur[i] = cur[i] + (t[i - 1] == s[j - 1] ? pre : 0);
        pre = temp;
      }
    }
    return cur[m];
  }
};
