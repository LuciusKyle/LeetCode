#include <assert.h>

#include <vector>

using std::vector;

class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    const size_t n = grid.size();
    if (grid[0][0] || grid[n - 1][n - 1]) return -1;
    int level = 0;
    vector<std::pair<int, int>> current_steps;
    current_steps.push_back({0, 0});
    do {
      vector<std::pair<int, int>> next_steps;
      for (const auto coordinate : current_steps) {
        if (coordinate.first == n - 1 && coordinate.second == n - 1) return level + 1;

        if (0 <= coordinate.first - 1 && 0 <= coordinate.second - 1 && grid[coordinate.first - 1][coordinate.second - 1] == 0) {
          next_steps.push_back({coordinate.first - 1, coordinate.second - 1});
          grid[coordinate.first - 1][coordinate.second - 1] = -1;
        }
        if (0 <= coordinate.first - 1 && grid[coordinate.first - 1][coordinate.second] == 0) {
          next_steps.push_back({coordinate.first - 1, coordinate.second});
          grid[coordinate.first - 1][coordinate.second] = -1;
        }
        if (0 <= coordinate.second - 1 && grid[coordinate.first][coordinate.second - 1] == 0) {
          next_steps.push_back({coordinate.first, coordinate.second - 1});
          grid[coordinate.first][coordinate.second - 1] = -1;
        }
        if (coordinate.first + 1 < n && coordinate.second + 1 < n && grid[coordinate.first + 1][coordinate.second + 1] == 0) {
          next_steps.push_back({coordinate.first + 1, coordinate.second + 1});
          grid[coordinate.first + 1][coordinate.second + 1] = -1;
        }
        if (coordinate.second + 1 < n && grid[coordinate.first][coordinate.second + 1] == 0) {
          next_steps.push_back({coordinate.first, coordinate.second + 1});
          grid[coordinate.first][coordinate.second + 1] = -1;
        }
        if (coordinate.first + 1 < n && grid[coordinate.first + 1][coordinate.second] == 0) {
          next_steps.push_back({coordinate.first + 1, coordinate.second});
          grid[coordinate.first + 1][coordinate.second] = -1;
        }
        if (0 <= coordinate.first - 1 && coordinate.second + 1 < n && grid[coordinate.first - 1][coordinate.second + 1] == 0) {
          next_steps.push_back({coordinate.first - 1, coordinate.second + 1});
          grid[coordinate.first - 1][coordinate.second + 1] = -1;
        }
        if (coordinate.first + 1 < n && 0 <= coordinate.second - 1 && grid[coordinate.first + 1][coordinate.second - 1] == 0) {
          next_steps.push_back({coordinate.first + 1, coordinate.second - 1});
          grid[coordinate.first + 1][coordinate.second - 1] = -1;
        }
      }
      current_steps = next_steps;
      ++level;
    } while (!current_steps.empty());
    return -1;
  }

 private:
};

int main(void) {
  vector<vector<int>> grid{{0, 1}, {1, 0}};
  Solution sln;
  int rtn = sln.shortestPathBinaryMatrix(grid);
  assert(2 == rtn);
  return 0;
}
