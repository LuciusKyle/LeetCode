
#include <vector>

using std::vector;

// 0118 and 0119 share a same solution.
class Solution {
 public:
  vector<int> getRow(const int rowIndex) {
    return generate(rowIndex + 1).back();
  }
  vector<vector<int>> generate(const int numRows) {
    vector<vector<int>> rtn;
    rtn.push_back(vector<int>(1, 1));
    for (int i = 2; i <= numRows; ++i) {
      rtn.push_back(vector<int>(1, 1));
      for (int ii = 1; ii < i - 1; ++ii)
        rtn.back().push_back(rtn[i - 2][ii - 1] + rtn[i - 2][ii]);
      rtn.back().push_back(1);
    }
    return rtn;
  }
};

int main(void) {
  Solution sln;
  auto rtn = sln.generate(5);
  auto rtn1 = sln.getRow(0);
  return 0;
}
