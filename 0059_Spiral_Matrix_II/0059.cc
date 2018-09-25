
#include <iostream>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> generateMatrix(const int n) {
    vector<vector<int>> rtn(n, vector<int>(n, 0));
    int left = 0;
    int right = n;
    int up = 0;
    int down = n;
    int count = 0;
    while (left < right) {
      for (int i = left; i < right; ++i) {
        rtn[up][i] = ++count;
      }
      for (int i = up + 1; i < down; ++i) {
        rtn[i][right - 1] = ++count;
      }
      for (int i = right - 1 - 1; i > left - 1; --i) {
        rtn[down - 1][i] = ++count;
      }
      for (int i = down - 1 - 1; i > up; --i) {
        rtn[i][left] = ++count;
      }

      ++left;
      --right;
      ++up;
      --down;
    }
    return rtn;
  }
};

int main(void) {
  Solution sln;
  auto rtn = sln.generateMatrix(4);
  for (const auto &line : rtn) {
    for (const auto ele : line) std::cout << ele << '\t';
    std::cout << '\n';
  }
  std::cout << '\n';

  rtn = sln.generateMatrix(5);
  for (const auto &line : rtn) {
    for (const auto ele : line) std::cout << ele << '\t';
    std::cout << '\n';
  }
  std::cout << '\n';

  rtn = sln.generateMatrix(6);
  for (const auto &line : rtn) {
    for (const auto ele : line) std::cout << ele << '\t';
    std::cout << '\n';
  }
  std::cout << '\n';

  return 0;
}
