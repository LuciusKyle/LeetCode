
#include <vector>

using std::vector;

class Solution {
 public:
  int countNegatives(vector<vector<int>>& grid) {
    const int rows = grid.size(), columns = grid[0].size();
    int answer = 0, column = 0;
    for (int row = rows - 1; 0 <= row; --row)
      for (; column < columns; ++column)
        if (grid[row][column] < 0) {
          answer += (columns - column);
          break;
        }
    return answer;
  }
};
