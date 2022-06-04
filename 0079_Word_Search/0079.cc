
#include <assert.h>

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  bool exist(vector<vector<char>>& board, const string word) {
    for (size_t i = 0; i < board.size(); ++i)
      for (size_t ii = 0; ii < board[i].size(); ++ii)
        if (word[0] == board[i][ii]) {
          const char ch = word[0];
          board[i][ii] = '\0';
          if (exist(board, word, 1, i, ii))
            return true;
          board[i][ii] = ch;
        }
    return false;
  }

 private:
  bool exist(vector<vector<char>>& board, const string& word, const size_t index_to_find, const size_t row, const size_t column) {
    if (index_to_find == word.size()) return true;
    const char ch = word[index_to_find];
    if (0 < row && board[row - 1][column] == word[index_to_find]) {
      board[row - 1][column] = '\0';
      if (exist(board, word, index_to_find + 1, row - 1, column))
        return true;
      board[row - 1][column] = ch;
    }
    if (0 < column && board[row][column - 1] == word[index_to_find]) {
      board[row][column - 1] = '\0';
      if (exist(board, word, index_to_find + 1, row, column - 1))
        return true;
      board[row][column - 1] = ch;
    }
    if (row < board.size() - 1 && board[row + 1][column] == word[index_to_find]) {
      board[row + 1][column] = '\0';
      if (exist(board, word, index_to_find + 1, row + 1, column))
        return true;
      board[row + 1][column] = ch;
    }
    if (column < board[0].size() - 1 && board[row][column + 1] == word[index_to_find]) {
      board[row][column + 1] = '\0';
      if (exist(board, word, index_to_find + 1, row, column + 1))
        return true;
      board[row][column + 1] = ch;
    }
    return false;
  }
};

int main(void) {
  const vector<vector<char>> test_board{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  Solution sln;
  auto test_board_copy = test_board;
  bool result = sln.exist(test_board_copy, "ABCCED");
  assert(result);
  test_board_copy = test_board;
  result = sln.exist(test_board_copy, "SEE");
  assert(result);
  test_board_copy = test_board;
  result = sln.exist(test_board_copy, "ABCB");
  assert(!result);
  return 0;
}
