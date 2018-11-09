
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  void gameOfLife(vector<vector<int>>& board) { gameOfLife(board, 0, 0); }

 private:
  void gameOfLife(vector<vector<int>>& board, const size_t row, const size_t column) {
    for (size_t this_row = row; this_row < board.size(); ++this_row)
      for (size_t this_column = this_row == row ? column : 0;
           this_column < board[0].size(); ++this_column) {
        if (NeedFlip(board, this_row, this_column)) {
          gameOfLife(board, this_row, this_column + 1);
          board[this_row][this_column] =
              board[this_row][this_column] == 0 ? 1 : 0;
          return;
        }
      }
  }
  bool NeedFlip(const vector<vector<int>>& board, const size_t row, const size_t column) {
    size_t live_count = 0;
    if (0 < row) {
      if (board[row - 1][column] == 1) ++live_count;  // up
      if (0 < column)
        if (board[row - 1][column - 1] == 1) ++live_count;  // left up
      if (column + 1 < board[0].size())
        if (board[row - 1][column + 1] == 1) ++live_count;  // right up
    }
    if (column + 1 < board[0].size())
      if (board[row][column + 1] == 1) ++live_count;  // right
    if (0 < column)
      if (board[row][column - 1] == 1) ++live_count;  // left
    if (row + 1 < board.size()) {
      if (board[row + 1][column] == 1) ++live_count;  // down
      if (column + 1 < board[0].size())
        if (board[row + 1][column + 1] == 1) ++live_count;  // down right
      if (0 < column)
        if (board[row + 1][column - 1]) ++live_count;  // down left
    }

    if (board[row][column] == 1) {
      if (live_count < 2) return true;
      if (3 < live_count) return true;
      return false;
    } else if (live_count == 3)
      return true;
    else
      return false;
  }
};

int main(void) {
  Solution sln;
  vector test_board{vector{0, 1, 0}, vector{0, 0, 1}, vector{1, 1, 1}, vector{0, 0, 0}};
  sln.gameOfLife(test_board);
  for (size_t row = 0; row < test_board.size(); ++row) {
    for (size_t column = 0; column < test_board[0].size(); ++column)
      cout << test_board[row][column] << ' ';
    cout << '\n';
  }

  cout << '\n';

  test_board = {vector{1, 1}, vector{1, 0}};
  sln.gameOfLife(test_board);
  for (size_t row = 0; row < test_board.size(); ++row) {
    for (size_t column = 0; column < test_board[0].size(); ++column)
      cout << test_board[row][column] << ' ';
    cout << '\n';
  }

  return 0;
}
