
#include <assert.h>
#include <array>
#include <string>
#include <vector>

using std::array;
using std::string;
using std::vector;

class Solution {
 public:
  int maxProduct(const vector<string>& words) {
    vector<unsigned int> charactor_mask(words.size(), 0u);
    for (size_t i = 0; i < words.size(); ++i)
      for (const auto ch : words[i]) charactor_mask[i] |= 1 << (ch - 'a');

    size_t rtn = 0;
    for (size_t i = 0; i < charactor_mask.size(); ++i)
      for (size_t ii = i + 1; ii < charactor_mask.size(); ++ii)
        if ((charactor_mask[i] & charactor_mask[ii]) == 0)
          rtn = std::max(rtn, (words[i].size() * words[ii].size()));

    return static_cast<int>(rtn);
  }
};

int main(void) {
  Solution sln;
  assert(16 == sln.maxProduct({"abcw", "baz", "foo", "bar", "xtfn", "abcdef"}));
  return 0;
}
