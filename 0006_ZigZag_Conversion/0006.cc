
#include <assert.h>

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

// beat 75%.
class Solution {
 public:
  string convert(const string s, const int numRows) {
    if (numRows == 1) return s;
    string rtn;
    rtn.reserve(s.size());
    int iteration_count = 0;
    const int period = numRows * 2 - 2;
    while ((iteration_count * (period)) < s.size()) {
      rtn.push_back(s[iteration_count * (period)]);
      ++iteration_count;
    }

    for (int i = 1; i < numRows - 1; ++i) {
      iteration_count = 0;
      while ((i + iteration_count * (period)) < s.size() || (period - i + iteration_count * (period)) < s.size()) {
        if ((i + iteration_count * (period)) < s.size())
          rtn.push_back(s[i + iteration_count * (period)]);
        if ((period - i + iteration_count * (period)) < s.size())
          rtn.push_back(s[period - i + iteration_count * (period)]);
        ++iteration_count;
      }
    }

    iteration_count = 0;
    while ((numRows - 1 + iteration_count * (period)) < s.size()) {
      rtn.push_back(s[numRows - 1 + iteration_count * (period)]);
      ++iteration_count;
    }
    return rtn;
  }
};

int main(void) {
  Solution sln;
  string rtn = sln.convert("ABCDEFGHIJKLMNO", 4);
  assert(rtn == "AGMBFHLNCEIKODJ");
  rtn = sln.convert("PAYPALISHIRING", 4);
  assert(rtn == "PINALSIGYAHRPI");
  rtn = sln.convert("PAYPALISHIRING", 3);
  assert(rtn == "PAHNAPLSIIGYIR");

  vector<int> index_dict;
  index_dict.reserve(1000);
  for (int i = 0; i < 1000; ++i) index_dict.push_back(i);

  // cout << "{";
  // for (int i = 0; i < all_index_dict.size(); ++i) {
  //   if (i % 17 == 0) cout << "\n";
  //   cout << "{";
  //   for (int ii = 0; ii < all_index_dict[i].size(); ++ii) {
  //     cout << all_index_dict[i][ii];
  //     if (ii != all_index_dict[i].size() - 1)
  //       cout << ",";
  //     else if (i != all_index_dict.size() - 1)
  //       cout << "},";
  //     else
  //       cout << "}";
  //   }
  // }
  // cout << "}" << endl;
  return 0;
}
