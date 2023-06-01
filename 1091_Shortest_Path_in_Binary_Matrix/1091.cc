
#include <assert.h>
#include <stddef.h>

#include <vector>

using std::vector;

class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    const int n = grid.size();
    if (grid[0][0] || grid[n - 1][n - 1]) return -1;
    grid[0][0] = -1;
    int level = 0;
    vector<std::pair<int, int>> current_steps, next_steps;
    current_steps.push_back({0, 0});
    const std::pair<int, int> kEightDirections[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    do {
      for (const auto coordinate : current_steps) {
        if (coordinate.first == n - 1 && coordinate.second == n - 1) return level + 1;
        for (const auto direction : kEightDirections)
          if ((0 <= coordinate.first + direction.first) && (coordinate.first + direction.first < n) && (0 <= coordinate.second + direction.second) && (coordinate.second + direction.second < n) && (grid[coordinate.first + direction.first][coordinate.second + direction.second] == 0)) {
            next_steps.push_back({coordinate.first + direction.first, coordinate.second + direction.second});
            grid[coordinate.first + direction.first][coordinate.second + direction.second] = -1;
          }
      }
      current_steps.swap(next_steps);
      next_steps.clear();
      ++level;
    } while (!current_steps.empty());
    return -1;
  }
};

int main(void) {
  vector<vector<int>> grid{{0, 1}, {1, 0}};
  Solution sln;
  int rtn = sln.shortestPathBinaryMatrix(grid);
  assert(2 == rtn);
  return 0;
}
