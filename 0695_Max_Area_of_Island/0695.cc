
#include <vector>

using std::vector;

class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int rtn = 0;
    int current_island = 2;
    for (size_t i = 0; i < grid.size(); ++i)
      for (size_t j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] == 1) {
          const int area = AreaCount(grid, i, j, current_island++);
          if (rtn < area) rtn = area;
        }

    return rtn;
  }

 private:
  int AreaCount(vector<vector<int>>& grid, const size_t row, const size_t column, const int current_island) {
    grid[row][column] = current_island;
    int rtn = 1;
    if (row != 0 && grid[row - 1][column] == 1)
      rtn += AreaCount(grid, row - 1, column, current_island);
    if (row + 1 < grid.size() && grid[row + 1][column] == 1)
      rtn += AreaCount(grid, row + 1, column, current_island);
    if (column != 0 && grid[row][column - 1] == 1)
      rtn += AreaCount(grid, row, column - 1, current_island);
    if (column + 1 < grid[0].size() && grid[row][column + 1] == 1)
      rtn += AreaCount(grid, row, column + 1, current_island);

    return rtn;
  }
};

int main(void) { return 0; }
