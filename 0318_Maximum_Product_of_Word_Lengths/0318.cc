
#include <array>
#include <string>
#include <vector>

using std::array;
using std::string;
using std::vector;

class Solution {
 public:
  int maxProduct(const vector<string>& words) {
    int rtn = 0;
    for (auto iter = words.cbegin(); iter != words.cend(); ++iter) {
      array<char, 26> charactor_dict{0};
      for (const auto ch : *iter) {
        charactor_dict[ch - 'a'] = 1;
      }
      for (auto inner_inter = iter; inner_inter != words.cend();
           ++inner_inter) {
        bool no_common_letters = true;
        for (const auto ch : *inner_inter) {
          if (charactor_dict[ch - 'a'] == 1) {
            no_common_letters = false;
            break;
          }
        }
        if (no_common_letters) {
          if (rtn < static_cast<int>(iter->size() * inner_inter->size()))
            rtn = static_cast<int>(iter->size() * inner_inter->size());
        }
      }
    }
    return rtn;
  }
};

int main(void) {
  Solution sln;
  int rtn = sln.maxProduct({"abcw", "baz", "foo", "bar", "xtfn", "abcdef"});
  return 0;
}
