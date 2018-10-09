

#include <vector>
#include <assert.h>

using std::vector;

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int rtn = 0;
    for (size_t row = 0; row < grid.size(); ++row)
      for (size_t column = 0; column < grid[0].size(); ++column)
        if (grid[row][column] == '1') {
          markIsland(grid, row, column);
          ++rtn;
        }
    return rtn;
  }

 private:
  void markIsland(vector<vector<char>>& grid, const size_t row,
                  const size_t column) {
    grid[row][column] = '2';
    if (row + 1 < grid.size() && grid[row + 1][column] == '1')
      markIsland(grid, row + 1, column);
    if (0 < row && grid[row - 1][column] == '1')
      markIsland(grid, row - 1, column);
    if (0 < column && grid[row][column - 1] == '1')
      markIsland(grid, row, column - 1);
    if (column + 1 < grid[0].size() && grid[row][column + 1] == '1')
      markIsland(grid, row, column + 1);
  }
};

int main(void) {
  Solution sln;
  vector test_sample{
      vector{'1', '1', '1', '1', '0'},
      vector{'1', '1', '0', '1', '0'},
      vector{'1', '1', '0', '0', '0'},
      vector{'0', '0', '0', '0', '0'}};
  assert(1==sln.numIslands(test_sample));
  return 0;
}
