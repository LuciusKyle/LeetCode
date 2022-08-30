
#include <memory.h>

#include <array>
#include <vector>

using std::vector;

// beats 82%.
class Solution {
 public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    const int rows = mat.size(), columns = mat[0].size();
    if (rows == 1 || columns == 1) return mat;
    int num_count[101] = {0};
    for (int i = rows - 1, arr_size = 0; 0 < i; --i) {
      for (int row = i, column = 0; row < rows && column < columns; ++row, ++column)
        ++num_count[mat[row][column]];
      for (int j = 0, row = i, column = 0; j < std::end(num_count) - std::begin(num_count); ++j)
        while (num_count[j] != 0) {
          mat[row++][column++] = j;
          --num_count[j];
        }
    }
    for (int i = 0; i < columns; ++i) {
      for (int row = 0, column = i; row < rows && column < columns; ++row, ++column)
        ++num_count[mat[row][column]];
      for (int j = 0, row = 0, column = i; j < std::end(num_count) - std::begin(num_count); ++j)
        while (num_count[j] != 0) {
          mat[row++][column++] = j;
          --num_count[j];
        }
    }
    return mat;
  }
};
