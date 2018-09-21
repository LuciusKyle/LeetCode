
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> spiralOrder(const vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return {};
    }
    int left = 0;
    int right = matrix[0].size();
    int up = 0;
    int down = matrix.size();

    vector<int> rtn;
    rtn.reserve(right * down);
    while (left < right && up < down) {
      for (int i = left; i < right; ++i)
       rtn.push_back(matrix[up][i]);
      if(down - up < 2)
        break;
      for (int i = up + 1; i < down; ++i)
       rtn.push_back(matrix[i][right - 1]);
      if(right - left < 2)
        break;
      for (int i = right - 1 - 1; i >= left; --i)
        rtn.push_back(matrix[down - 1][i]);
      for (int i = down - 1 - 1; i > up; --i)
       rtn.push_back(matrix[i][left]);
      ++left;
      --right;
      ++up;
      --down;
    }
    return rtn;
  }
};

int main(void) {
  vector<int> row_0{1, 2, 3, 4};
  vector<int> row_1{5, 6, 7, 8};
  vector<int> row_2{9, 10, 11, 12};
  vector<vector<int>> test_vec{row_0, row_1, row_2};
  Solution sln;
  auto rtn = sln.spiralOrder(test_vec);

  row_0 = {2, 3};
  test_vec = {row_0};
  rtn = sln.spiralOrder(test_vec);

  row_0 = {1, 2, 3};
  row_1 = {4, 5, 6};
  row_2 = {7, 8, 9};
  test_vec = {row_0, row_1, row_2};
  rtn = sln.spiralOrder(test_vec);

  row_0 = {1};
  row_1 = {2};
  row_2 = {3};
  test_vec = {row_0, row_1, row_2};
  rtn = sln.spiralOrder(test_vec);

  test_vec = {row_0, row_1};
  rtn = sln.spiralOrder(test_vec);

  return 0;
}
