
#include <vector>

using std::vector;

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    const size_t rows = matrix.size();
    const size_t columns = matrix.empty() ? 0 : matrix[0].size();
    if (rows == 0 || columns == 0) return;
    bool first_row_zero = false;
    bool first_column_zero = false;
    for (size_t i = 0; i < rows; ++i)
      for (size_t ii = 0; ii < columns; ++ii)
        if (matrix[i][ii] == 0)
          if (i == 0 || ii == 0) {
            if (i == 0) first_row_zero = true;
            if (ii == 0) first_column_zero = true;
          } else {
            matrix[i][0] = 0;
            matrix[0][ii] = 0;
          }

    for (size_t i = 1; i < rows; ++i)
      if (matrix[i][0] == 0)
        for (size_t ii = 0; ii < columns; ++ii) matrix[i][ii] = 0;
    for (size_t ii = 0; ii < columns; ++ii)
      if (matrix[0][ii] == 0)
        for (size_t i = 0; i < rows; ++i) matrix[i][ii] = 0;

    if (first_column_zero)
      for (size_t i = 0; i < rows; ++i) matrix[i][0] = 0;
    if (first_row_zero)
      for (size_t i = 0; i < columns; ++i) matrix[0][i] = 0;
  }
};

int main(void) {
  Solution sln;
  vector test_sample{vector{0, 1, 2, 0}, vector{3, 4, 5, 2},
                     vector{1, 3, 1, 5}};
  test_sample = vector<vector<int>>{vector{1,0}};
  sln.setZeroes(test_sample);
  return 0;
}
