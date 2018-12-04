
#include <set>
#include <string>
#include <vector>

using std::set;
using std::string;
using std::vector;

class Solution {
 public:
  int maxProduct(const vector<string>& words) {
    int rtn = 0;
    for (auto iter = words.cbegin(); iter != words.cend(); ++iter) {
      const set<char> this_word(iter->cbegin(), iter->cend());
      for (auto inner_inter = iter; inner_inter != words.cend();
           ++inner_inter) {
        bool no_common_letters = true;
        for (const auto ch : *inner_inter) {
          if (this_word.find(ch) != this_word.end()) {
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
