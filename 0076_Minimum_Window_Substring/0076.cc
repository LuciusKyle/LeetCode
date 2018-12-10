
#include <array>
#include <string>

using std::array;
using std::string;

class Solution {
 public:
  string minWindow(const string s, const string t) {
    array<bool, 256> ch_dict{false};
    array<size_t, 256> ch_count{0};
    for (const auto ch : t) ch_dict[ch] = true;
    for (const auto ch : s) ++ch_count[ch];

    

    return "";
  }
};

int main(void) {
  Solution sln;

  return 0;
}
