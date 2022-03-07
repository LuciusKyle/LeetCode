
#include <assert.h>

#include <array>
#include <unordered_set>
#include <vector>

using std::array;
using std::unordered_set;
using std::vector;

class Solution {
 public:
  Solution() : dict_{0} {}

  bool isValidSudoku(const vector<vector<char>>& board) {
    for (size_t row = 0; row < board.size(); ++row)
      for (size_t column = 0; column < board[row].size(); ++column)
        if (board[row][column] != '.') {
          // check row.
          if (dict_[0][row][board[row][column] - '1'])
            return false;
          else
            dict_[0][row][board[row][column] - '1'] = 1;

          // check column.
          if (dict_[1][column][board[row][column] - '1'])
            return false;
          else
            dict_[1][column][board[row][column] - '1'] = 1;

          // check sub-box.
          if (dict_[2][(row / 3) * 3 + column / 3][board[row][column] - '1'])
            return false;
          else
            dict_[2][(row / 3) * 3 + column / 3][board[row][column] - '1'] = 1;
        }
    return true;
  }

 private:
  char dict_[3][9][9];
};
