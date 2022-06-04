
#include <assert.h>

#include <algorithm>
#include <execution>
#include <numeric>
#include <vector>

using std::vector;

class NumMatrix {
 public:
  NumMatrix(const vector<vector<int>>& matrix) : prefix_sum_matrix_(matrix.size() + 1, vector<int>(matrix[0].size() + 1)) {
    const size_t rows = matrix.size(), columns = matrix[0].size();

    for (size_t row = 0; row < rows; ++row) {
      int temp_sum = 0;
      for (size_t column = 0; column < columns; ++column) {
        temp_sum += matrix[row][column];
        prefix_sum_matrix_[row + 1][column + 1] = prefix_sum_matrix_[row][column + 1] + temp_sum;
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) { return prefix_sum_matrix_[row2 + 1][col2 + 1] + prefix_sum_matrix_[row1][col1] - prefix_sum_matrix_[row2 + 1][col1] - prefix_sum_matrix_[row1][col2 + 1]; }

 private:
  vector<vector<int>> prefix_sum_matrix_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main(void) {
  NumMatrix test_mat({{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}});
  int rtn = test_mat.sumRegion(2, 1, 4, 3);
  assert(rtn == 8);
  rtn = test_mat.sumRegion(1, 1, 2, 2);
  assert(rtn == 11);
  rtn = test_mat.sumRegion(1, 2, 2, 4);
  assert(rtn == 12);
  return 0;
}
