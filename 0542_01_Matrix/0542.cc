
#include <assert.h>

#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    vector<vector<int>> distance_matrix(matrix.size(), vector<int>(matrix[0].size(), -1));
    vector<std::pair<int, int>> current_level;
    for (int row = 0; row < matrix.size(); ++row) {
      for (int column = 0; column < matrix[0].size(); ++column) {
        if (matrix[row][column] == 0) {
          current_level.push_back({row, column});
          distance_matrix[row][column] = 0;
        }
      }
    }
    int distance = 1;
    const int bottom_boundary = matrix.size(), right_boundary = matrix[0].size();
    do {
      vector<std::pair<int, int>> next_level;
      for (const auto& coordinate : current_level) {
        // up
        if (0 <= coordinate.first - 1 && distance_matrix[coordinate.first - 1][coordinate.second] == -1) {
          distance_matrix[coordinate.first - 1][coordinate.second] = distance;
          next_level.push_back({coordinate.first - 1, coordinate.second});
        }
        // down
        if (coordinate.first + 1 < bottom_boundary && distance_matrix[coordinate.first + 1][coordinate.second] == -1) {
          distance_matrix[coordinate.first + 1][coordinate.second] = distance;
          next_level.push_back({coordinate.first + 1, coordinate.second});
        }
        // left
        if (0 <= coordinate.second - 1 && distance_matrix[coordinate.first][coordinate.second - 1] == -1) {
          distance_matrix[coordinate.first][coordinate.second - 1] = distance;
          next_level.push_back({coordinate.first, coordinate.second - 1});
        }
        // right
        if (coordinate.second + 1 < right_boundary && distance_matrix[coordinate.first][coordinate.second + 1] == -1) {
          distance_matrix[coordinate.first][coordinate.second + 1] = distance;
          next_level.push_back({coordinate.first, coordinate.second + 1});
        }
      }
      ++distance;
      current_level = next_level;
    } while (!current_level.empty());
    return distance_matrix;
  }
};

int main(void) {
  vector<vector<int>> test_vec{{0, 0, 0}};
  Solution sln;
  auto ret = sln.updateMatrix(test_vec);
  return 0;
}
