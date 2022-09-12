
#include <string>
#include <vector>
#include <string_view>

using std::string;
using std::vector;

// constexpr char kDict[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
class Solution {
 public:
  string shiftingLetters(string s, vector<int>& shifts) {
    const int length = s.size();
    int pre_shift = 0;
    for (int i = length - 1; 0 <= i; --i) {
      shifts[i] = (shifts[i] + pre_shift) % 26;
      pre_shift = shifts[i];
      s[i] = 'z' < (s[i] + shifts[i]) ? s[i] + shifts[i] - 26 : s[i] + shifts[i];
    }
    return s;
  }
};