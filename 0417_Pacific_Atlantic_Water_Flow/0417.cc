
#include <vector>

using std::vector;

constexpr int kPacificMask = 1 << 28;
constexpr int kAtlanticMask = kPacificMask << 1;
constexpr int kOceanMask = kPacificMask | kAtlanticMask;

class Solution {
 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    const int rows = heights.size(), columns = heights[0].size();
    vector<std::pair<int, int>> current_cells, next_cells;
    for (int row = 0; row < rows; ++row) {
      heights[row][0] |= kPacificMask;
      current_cells.push_back({row, 0});
    }
    for (int column = 1; column < columns; ++column) {
      heights[0][column] |= kPacificMask;
      current_cells.push_back({0, column});
    }
    while (!current_cells.empty()) {
      for (const auto cell : current_cells) {
        // N
        if (cell.first != 0 && (heights[cell.first - 1][cell.second] & kPacificMask) == 0 && (heights[cell.first][cell.second] & ~kOceanMask) <= (heights[cell.first - 1][cell.second] & ~kOceanMask)) {
          next_cells.push_back({cell.first - 1, cell.second});
          heights[cell.first - 1][cell.second] |= kPacificMask;
        }
        // E
        if (cell.second + 1 != columns && (heights[cell.first][cell.second + 1] & kPacificMask) == 0 && (heights[cell.first][cell.second] & ~kOceanMask) <= (heights[cell.first][cell.second + 1] & ~kOceanMask)) {
          next_cells.push_back({cell.first, cell.second + 1});
          heights[cell.first][cell.second + 1] |= kPacificMask;
        }
        // W
        if (cell.second != 0 && (heights[cell.first][cell.second - 1] & kPacificMask) == 0 && (heights[cell.first][cell.second] & ~kOceanMask) <= (heights[cell.first][cell.second - 1] & ~kOceanMask)) {
          next_cells.push_back({cell.first, cell.second - 1});
          heights[cell.first][cell.second - 1] |= kPacificMask;
        }
        // S
        if (cell.first + 1 != rows && (heights[cell.first + 1][cell.second] & kPacificMask) == 0 && (heights[cell.first][cell.second] & ~kOceanMask) <= (heights[cell.first + 1][cell.second] & ~kOceanMask)) {
          next_cells.push_back({cell.first + 1, cell.second});
          heights[cell.first + 1][cell.second] |= kPacificMask;
        }
      }
      current_cells.swap(next_cells);
      next_cells.clear();
    }

    current_cells.clear();
    next_cells.clear();
    for (int row = 0; row < rows; ++row) {
      heights[row][columns - 1] |= kAtlanticMask;
      current_cells.push_back({row, columns - 1});
    }
    for (int column = 0; column < columns - 1; ++column) {
      heights[rows - 1][column] |= kAtlanticMask;
      current_cells.push_back({rows - 1, column});
    }
    while (!current_cells.empty()) {
      for (const auto cell : current_cells) {
        // N
        if (cell.first != 0 && (heights[cell.first - 1][cell.second] & kAtlanticMask) == 0 && (heights[cell.first][cell.second] & ~kOceanMask) <= (heights[cell.first - 1][cell.second] & ~kOceanMask)) {
          next_cells.push_back({cell.first - 1, cell.second});
          heights[cell.first - 1][cell.second] |= kAtlanticMask;
        }
        // E
        if (cell.second + 1 != columns && (heights[cell.first][cell.second + 1] & kAtlanticMask) == 0 && (heights[cell.first][cell.second] & ~kOceanMask) <= (heights[cell.first][cell.second + 1] & ~kOceanMask)) {
          next_cells.push_back({cell.first, cell.second + 1});
          heights[cell.first][cell.second + 1] |= kAtlanticMask;
        }
        // W
        if (cell.second != 0 && (heights[cell.first][cell.second - 1] & kAtlanticMask) == 0 && (heights[cell.first][cell.second] & ~kOceanMask) <= (heights[cell.first][cell.second - 1] & ~kOceanMask)) {
          next_cells.push_back({cell.first, cell.second - 1});
          heights[cell.first][cell.second - 1] |= kAtlanticMask;
        }
        // S
        if (cell.first + 1 != rows && (heights[cell.first + 1][cell.second] & kAtlanticMask) == 0 && (heights[cell.first][cell.second] & ~kOceanMask) <= (heights[cell.first + 1][cell.second] & ~kOceanMask)) {
          next_cells.push_back({cell.first + 1, cell.second});
          heights[cell.first + 1][cell.second] |= kAtlanticMask;
        }
      }
      current_cells.swap(next_cells);
      next_cells.clear();
    }

    vector<vector<int>> answer;
    for (int row = 0; row < rows; ++row) {
      for (int column = 0; column < columns; ++column) {
        if ((heights[row][column] & kOceanMask) == kOceanMask) answer.push_back(vector<int>{row, column});
      }
    }
    return answer;
  }
};

int main(void) {
  vector<vector<int>> test_island = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
  Solution sln;
  sln.pacificAtlantic(test_island);
  return 0;
}