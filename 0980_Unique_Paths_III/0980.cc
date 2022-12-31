
#include <vector>

using std::vector;

class Solution {
 public:
  Solution() : empty_square_count_(0), result_(0) {}
  int uniquePathsIII(vector<vector<int>>& grid) {
    int empty_square_count = 0, starting_row = 0, starting_column = 0;
    for (int row = 0; row < grid.size(); ++row)
      for (int column = 0; column < grid[0].size(); ++column)
        if (grid[row][column] == 0) {
          ++empty_square_count;
        } else if (grid[row][column] == 1) {
          starting_row = row;
          starting_column = column;
        }
    empty_square_count_ = empty_square_count;
    uniquePathsIII(grid, starting_row, starting_column, 0);
    return result_;
  }

 private:
  void uniquePathsIII(vector<vector<int>>& grid, int curr_row, int curr_column, int steps_count) {
    grid[curr_row][curr_column] = -2;
    // up
    if (curr_row != 0) {
      if (grid[curr_row - 1][curr_column] == 2 && steps_count == empty_square_count_)
        ++result_;
      if (grid[curr_row - 1][curr_column] == 0)
        uniquePathsIII(grid, curr_row - 1, curr_column, steps_count + 1);
    }

    // down
    if (curr_row + 1 < grid.size()) {
      if (grid[curr_row + 1][curr_column] == 2 && steps_count == empty_square_count_)
        ++result_;
      if (grid[curr_row + 1][curr_column] == 0)
        uniquePathsIII(grid, curr_row + 1, curr_column, steps_count + 1);
    }

    // left
    if (curr_column != 0) {
      if (grid[curr_row][curr_column - 1] == 2 && steps_count == empty_square_count_)
        ++result_;
      if (grid[curr_row][curr_column - 1] == 0)
        uniquePathsIII(grid, curr_row, curr_column - 1, steps_count + 1);
    }

    // right
    if (curr_column + 1 < grid[0].size()) {
      if (grid[curr_row][curr_column + 1] == 2 && steps_count == empty_square_count_)
        ++result_;
      if (grid[curr_row][curr_column + 1] == 0)
        uniquePathsIII(grid, curr_row, curr_column + 1, steps_count + 1);
    }
    grid[curr_row][curr_column] = 0;
  }
  int empty_square_count_;
  int result_;
};