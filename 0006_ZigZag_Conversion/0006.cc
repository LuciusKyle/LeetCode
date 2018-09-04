
#include <assert.h>
#include <string>

using std::string;

class Solution {
 public:
  string convert(string s, int numRows) {
    assert(numRows > 0 && s.size() > 0);
    const int OneGroup = numRows * 2 - 2;
    const int GroupCount = s.size() / OneGroup + 1;

    string rtn_str;
    for (int i = 0; i < numRows; ++i) {
      int first_charactor_index = i;
      int second_charactor_index = OneGroup - i;
      for (int ii = 0; ii < GroupCount; ++ii) {
        if (first_charactor_index + ii * OneGroup < s.size())
          rtn_str.push_back(s[first_charactor_index + ii * OneGroup]);
        if (first_charactor_index != second_charactor_index &&
            second_charactor_index != OneGroup &&
            second_charactor_index + ii * OneGroup < s.size())
          rtn_str.push_back(s[second_charactor_index + ii * OneGroup]);
      }
    }
    return rtn_str;
  }
};

int main(void) {
  Solution sln;
  auto rtn = sln.convert("PAYPALISHIRING", 4);
  assert(rtn == "PINALSIGYAHRPI");
  rtn = sln.convert("PAYPALISHIRING", 3);
  assert(rtn == "PAHNAPLSIIGYIR");
  return 0;
}
