
#include<vector>

using std::vector;


// 0118 and 0119 share a same solution.
class Solution {
 public:
  vector<int> getRow(const int rowIndex) {
    return generate(rowIndex + 1).back();
  }
  vector<vector<int>> generate(const int numRows) {
    vector<vector<int>> rtn;
    for (int i = 1; i <= numRows; ++i) {
      rtn.push_back(vector<int>());
      for (int ii = 0; ii < i; ++ii) {
        if (ii == 0) {
          rtn.back().push_back(1);
          continue;
        }
        if (ii == i - 1) {
          rtn.back().push_back(1);
          continue;
        }
        rtn.back().push_back(rtn[i - 2][ii - 1] + rtn[i - 2][ii]);
      }
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
