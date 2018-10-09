
#include <vector>

using std::vector;

class Solution {
 public:
  void solve(vector<vector<char>> &board) {
    if (board.empty()) return;
    for (size_t i = 0; i < board.size(); ++i) {
      if (board[i][0] == 'O') markIsland(board, i, 0);
      if (board[i][board[0].size() - 1] == 'O')
        markIsland(board, i, board[0].size() - 1);
    }
    for (size_t ii = 0; ii < board[0].size(); ++ii) {
      if (board[0][ii] == 'O') markIsland(board, 0, ii);
      if (board[board.size() - 1][ii] == 'O')
        markIsland(board, board.size() - 1, ii);
    }
    for (size_t i = 0; i < board.size(); ++i)
      for (size_t ii = 0; ii < board[0].size(); ++ii)
        if (board[i][ii] == 'P')
          board[i][ii] = 'O';
        else
          board[i][ii] = 'X';
  }

 private:
  // reuse the function in 200. Number of Islands[leetcode.com/problems].
  // function name is inappropriate.
  void markIsland(vector<vector<char>> &grid, const size_t row, const size_t column) {
    grid[row][column] = 'P';
    if (row + 1 < grid.size() && grid[row + 1][column] == 'O')
      markIsland(grid, row + 1, column);
    if (0 < row && grid[row - 1][column] == 'O')
      markIsland(grid, row - 1, column);
    if (0 < column && grid[row][column - 1] == 'O')
      markIsland(grid, row, column - 1);
    if (column + 1 < grid[0].size() && grid[row][column + 1] == 'O')
      markIsland(grid, row, column + 1);
  }
};
