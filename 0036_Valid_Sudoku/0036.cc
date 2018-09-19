
#include <assert.h>
#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution {
 public:
  Solution() : columns(9), rows(9), squares(9) {
		for (auto &my_set : columns) my_set.reserve(9);
		for (auto &my_set : rows) my_set.reserve(9);
		for (auto &my_set : squares) my_set.reserve(9);
  }

  bool isValidSudoku(const vector<vector<char>>& board) {
    for (size_t row = 0; row < board.size(); ++row)
      for (size_t column = 0; column < board[row].size(); ++column)
        if (board[row][column] != '.')
          if (!fill_one_cell(row, column, board[row][column])) return false;
    return true;
  }

 private:
  bool fill_one_cell(const size_t row, const size_t column, const char value) {
    // assert('1' <= value && value <= '9');
    auto rtn = columns[column].insert(value);
    if (!rtn.second) return false;
    rtn = rows[row].insert(value);
    if (!rtn.second) {
      columns[column].erase(value);
      return false;
    }
    rtn = squares[(row / 3) * 3 + column / 3].insert(value);
    if (!rtn.second) {
      columns[column].erase(value);
      rows[column].erase(value);
      return false;
    }
    return true;
  }

  vector<unordered_set<char>> columns;
  vector<unordered_set<char>> rows;
  vector<unordered_set<char>> squares;
};
