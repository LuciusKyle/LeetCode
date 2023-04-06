
#include <vector>

using std::vector;

class Solution {
 public:
  int closedIsland(vector<vector<int>>& grid) {
    const int rows = grid.size(), columns = grid[0].size();
    // first row and bottom row
    for (int i = 0; i < columns; ++i) {
      if (grid[0][i] == 0) fillIsland(grid, 0, i, -1);
      if (grid[rows - 1][i] == 0) fillIsland(grid, rows - 1, i, -1);
    }

    // left and right column
    for (int i = 1; i < rows - 1; ++i) {
      if (grid[i][0] == 0) fillIsland(grid, i, 0, -1);
      if (grid[i][columns - 1] == 0) fillIsland(grid, i, columns - 1, -1);
    }

    int result = 0;
    for (int row = 0; row < rows; ++row)
      for (int column = 0; column < columns; ++column)
        if (grid[row][column] == 0) fillIsland(grid, row, column, ++result);
    return result;
  }

 private:
  void fillIsland(vector<vector<int>>& grid, int row, int column, int num) {
    grid[row][column] = num;
    // left
    if (column != 0 && grid[row][column - 1] == 0)
      fillIsland(grid, row, column - 1, num);

    // right
    if (column + 1 != grid[0].size() && grid[row][column + 1] == 0)
      fillIsland(grid, row, column + 1, num);

    // up
    if (row != 0 && grid[row - 1][column] == 0)
      fillIsland(grid, row - 1, column, num);

    // down
    if (row + 1 != grid.size() && grid[row + 1][column] == 0)
      fillIsland(grid, row + 1, column, num);
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> test_vec{{1, 1, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 1, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 0}};
  // vector<vector<int>> test_vec{{0, 0, 1, 0, 0}, {0, 1, 0, 1, 0}, {0, 1, 1, 1, 0}};
  // vector<vector<int>> test_vec{{1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 1}, {1, 0, 1, 1, 1, 0, 1}, {1, 0, 1, 0, 1, 0, 1}, {1, 0, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1}};
  vector<vector<int>> test_vec2{{0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1}, {0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1}, {1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0}, {1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1}, {1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1}, {1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0}, {1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0}, {1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1}, {1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0}, {1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1}, {0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0}, {1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1}};
  Solution sln;
  int result = sln.closedIsland(test_vec2);
  result = sln.closedIsland(test_vec);
  return 0;
}