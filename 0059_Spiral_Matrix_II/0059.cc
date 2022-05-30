
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Solution {
 public:
  vector<vector<int>> generateMatrix(const int n) {
    vector<vector<int>> rtn(n, vector<int>(n, 0));
    int left = 0,
        right = n,
        up = 0,
        down = n,
        count = 0;
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

constexpr int kAnswerLength = 20;

int main(void) {
  Solution sln;
  cout << "const vector<vector<vector<int>>> kAllAnswers\n{\n";
  for (int i = 0; i < kAnswerLength; ++i) {
    auto rtn = sln.generateMatrix(i + 1);
    cout << "{";

    for (size_t row = 0; row < rtn.size(); ++row) {
      cout << "{";

      for (size_t column = 0; column < rtn[row].size(); ++column) {
        cout << rtn[row][column];
        if (column != rtn[row].size() - 1)
          cout << ", ";
      }

      if (row == rtn.size() - 1)
        cout << "}";
      else
        cout << "},\n";
    }

    if (i == kAnswerLength - 1)
      cout << "}\n";
    else
      cout << "},\n\n";
  }
  cout << "};";

  cout << std::endl;

  return 0;
}
