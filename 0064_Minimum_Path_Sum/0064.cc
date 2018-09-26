
#include <limits.h>
#include <algorithm>  // for std::min();
#include <vector>

using std::vector;

class Solution {
 public:
  int minPathSum(const vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), INT_MAX));
    return uniquePaths(dp, grid, grid.size() - 1, grid[0].size() - 1);
  }

 private:
  int uniquePaths(vector<vector<int>>& dp, const vector<vector<int>>& grid,
                  const int row, const int column) {
    if (dp[row][column] != INT_MAX) return dp[row][column];
    if (row == 0 && column == 0) return grid[0][0];
    if (row == 0)
      return grid[row][column] + uniquePaths(dp, grid, row, column - 1);
    if (column == 0)
      return grid[row][column] + uniquePaths(dp, grid, row - 1, column);
    return dp[row][column] = grid[row][column] +
                             std::min(uniquePaths(dp, grid, row - 1, column),
                                      uniquePaths(dp, grid, row, column - 1));
  }
};

int main(void) {
  vector<vector<int>> test_vec{vector<int>{1, 3, 1}, vector<int>{1, 5, 1},
                               vector<int>{4, 2, 1}};
  Solution sln;
  int rtn = sln.minPathSum(test_vec);

  return 0;
}
