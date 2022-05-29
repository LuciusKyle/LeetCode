
#include <assert.h>

#include <algorithm>
#include <array>
#include <string>
#include <vector>

using std::array;
using std::string;
using std::vector;

constexpr unsigned int bits_map[] = {1 << 0, 1 << 1, 1 << 2, 1 << 3, 1 << 4, 1 << 5, 1 << 6, 1 << 7, 1 << 8, 1 << 9, 1 << 10, 1 << 11, 1 << 12, 1 << 13, 1 << 14, 1 << 15, 1 << 16, 1 << 17, 1 << 18, 1 << 19, 1 << 20, 1 << 21, 1 << 22, 1 << 23, 1 << 24, 1 << 25};

class Solution {
 public:
  int maxProduct(const vector<string>& words) {
    const size_t words_size = words.size();
    vector<unsigned int> charactor_mask(words_size, 0u);
    for (size_t i = 0; i < words_size; ++i)
      for (const auto ch : words[i]) charactor_mask[i] |= bits_map[ch - 'a'];

    int rtn = 0;
    for (size_t i = 0; i < words_size; ++i)
      for (size_t j = i + 1; j < words_size; ++j)
        if ((charactor_mask[i] & charactor_mask[j]) == 0)
          rtn = std::max(rtn, int(words[i].size()) * int(words[j].size()));
    return rtn;
  }
};

int main(void) {
  Solution sln;
  int rtn = sln.maxProduct({"abcw", "baz", "foo", "bar", "xtfn", "abcdef"});
  assert(16 == rtn);
  return 0;
}
