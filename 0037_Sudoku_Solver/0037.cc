
#include <iostream>
#include <unordered_set>
#include <vector>

using std::cout;
using std::endl;
using std::unordered_set;
using std::vector;

class Solution {
 public:
  Solution() : rows_{{0}}, columns_{{0}}, squares_{{0}} {}

  void solveSudoku(vector<vector<char>> &board) {
    for (int row = 0; row < 9; ++row)
      for (int column = 0; column < 9; ++column)
        if (board[row][column] != '.') {
          const int value = board[row][column] - '1';
          rows_[row][value] = 1;
          columns_[column][value] = 1;
          squares_[(row / 3) * 3 + column / 3][value] = 1;
        }
    FillSudoku(board, 0, 0);
  }

 private:
  bool FillSudoku(vector<vector<char>> &board, const int current_row, const int current_column) {
    for (int row = current_row; row < 9; ++row)
      for (int column = row == current_row ? current_column : 0; column < 9; ++column)
        if (board[row][column] == '.') {
          for (char value = '1'; value <= '9'; ++value)
            if (FillOneCell(row, column, value - '1')) {
              board[row][column] = value;
              if (FillSudoku(board, row, column))
                return true;
              else {
                EraseOneCell(row, column, value - '1');
                board[row][column] = '.';
              }
            }
          return false;
        }
    return true;
  }

  bool FillOneCell(const int row, const int column, const int value) {
    if (0 == rows_[row][value] && 0 == columns_[column][value] && 0 == squares_[(row / 3) * 3 + column / 3][value]) {
      rows_[row][value] = 1;
      columns_[column][value] = 1;
      squares_[(row / 3) * 3 + column / 3][value] = 1;
      return true;
    } else
      return false;
  }

  void EraseOneCell(const int row, const int column, const int value) {
    rows_[row][value] = 0;
    columns_[column][value] = 0;
    squares_[(row / 3) * 3 + column / 3][value] = 0;
  }

  int rows_[9][9];
  int columns_[9][9];
  int squares_[9][9];
};

int main(void) {
  Solution sln;
  vector<vector<char>> test_case = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  sln.solveSudoku(test_case);
  for (const auto &vec : test_case) {
    for (const int val : vec)
      cout << val - '0' << ' ';
    cout << endl;
  }
  cout << endl;
  return 0;
}