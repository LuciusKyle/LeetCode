
#include <limits.h>

#include <algorithm>  // for std::min();
#include <vector>

using std::vector;

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    for (int row = grid.size() - 1, column = int(grid[row].size()) - 2; 0 <= column; --column)
      grid[row][column] += grid[row][column + 1];
    for (int row = int(grid.size()) - 2; 0 <= row; --row) {
      if (grid[row].size() != 1)
        grid[row][int(grid[row].size()) - 1] += grid[row + 1][int(grid[row].size()) - 1];
      for (int column = int(grid[row].size()) - 2; 0 <= column; --column)
        grid[row][column] += std::min(grid[row + 1][column], grid[row][column + 1]);
    }
    return grid[0][0];
  }
};

int main(void) {
  vector test_vec{vector{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  Solution sln;
  int rtn = sln.minPathSum(test_vec);
  return 0;
}
