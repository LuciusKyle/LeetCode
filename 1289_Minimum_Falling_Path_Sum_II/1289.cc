
#include <limits.h>

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    const int n = grid.size();
    vector<int> pre_level;
    pre_level = grid[0];
    int min_and_second_min[4] = {100, -1, 100, -1};
    for (int i = 0; i < n; ++i)
      if (grid[0][i] <= min_and_second_min[2]) {
        min_and_second_min[2] = grid[0][i];
        min_and_second_min[3] = i;
        if (min_and_second_min[2] < min_and_second_min[0]) {
          std::swap(min_and_second_min[0], min_and_second_min[2]);
          std::swap(min_and_second_min[1], min_and_second_min[3]);
        }
      }
    for (int row = 1; row < n; ++row) {
      int pre_min_and_second_min[4] = {min_and_second_min[0], min_and_second_min[1], min_and_second_min[2], min_and_second_min[3]};
      min_and_second_min[0] = INT_MAX;
      min_and_second_min[2] = INT_MAX;
      min_and_second_min[1] = -1;
      min_and_second_min[3] = -1;
      for (int column = 0; column < n; ++column) {
        const int curr_val = grid[row][column] + (column == pre_min_and_second_min[1] ? pre_min_and_second_min[2] : pre_min_and_second_min[0]);
        if (curr_val < min_and_second_min[2]) {
          min_and_second_min[2] = curr_val;
          min_and_second_min[3] = column;
          if (min_and_second_min[2] < min_and_second_min[0]) {
            std::swap(min_and_second_min[0], min_and_second_min[2]);
            std::swap(min_and_second_min[1], min_and_second_min[3]);
          }
        }
      }
    }
    return min_and_second_min[0];
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> test_vec{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  // vector<vector<int>> test_vec{{7}};
  Solution sln;
  cout << sln.minFallingPathSum(test_vec);
  cout << endl;
  return 0;
}