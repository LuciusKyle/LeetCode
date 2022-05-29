
#include <vector>

using std::vector;

constexpr int kBoardLength = 8;

class Solution {
 public:
  int numRookCaptures(vector<vector<char>>& board) {
    for (int row = 0; row < kBoardLength; ++row)
      for (int column = 0; column < kBoardLength; ++column)
        if (board[row][column] == 'R') {
          int rtn = 0;
          int movement = 1;
          // up
          while (0 <= row - movement) {
            if (board[row - movement][column] == 'B') break;
            if (board[row - movement][column] == 'p') {
              ++rtn;
              break;
            }
            ++movement;
          }
          // down
          movement = 1;
          while (row + movement < kBoardLength) {
            if (board[row + movement][column] == 'B') break;
            if (board[row + movement][column] == 'p') {
              ++rtn;
              break;
            }
            ++movement;
          }
          // left
          movement = 1;
          while (0 <= column - movement) {
            if (board[row][column - movement] == 'B') break;
            if (board[row][column - movement] == 'p') {
              ++rtn;
              break;
            }
            ++movement;
          }
          // right
          movement = 1;
          while (column + movement < kBoardLength) {
            if (board[row][column + movement] == 'B') break;
            if (board[row][column + movement] == 'p') {
              ++rtn;
              break;
            }
            ++movement;
          }
          return rtn;
        }
    return -1;
  }
};