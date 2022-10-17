
#include <string>

using std::string;

constexpr int kPangram = (1 << 26) - 1;

class Solution {
 public:
  bool checkIfPangram(const string sentence) {
    int dict_ = 0;
    for (const char ch : sentence)
      dict_ |= (1 << (ch - 'a'));
    return dict_ == kPangram;
  }
};
