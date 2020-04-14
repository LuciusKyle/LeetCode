
#include <limits.h>

#include <chrono>
#include <array>
#include <iostream>
#include <numeric>
#include <vector>

using std::vector;

class Solution {
 public:
  int leastBricks(const vector<vector<int>>& wall) {
    vector<std::array<int, 2>> pre_wall;
    const int wall_hight = std::accumulate(wall[0].cbegin(), wall[0].cend(), 0);
    for (int i = 0; i < wall.size(); ++i) {
      int pos = 0, it = 0;
      vector<std::array<int, 2>> cur_wall;
      for (int j = 0; j < wall[i].size(); ++j) {
        pos += wall[i][j];        
        while (it != pre_wall.size() && pre_wall[it][0] < pos) {
          cur_wall.push_back({pre_wall[it][0], pre_wall[it][1] + 1});
          ++it;
        }

        if (it != pre_wall.size() && pre_wall[it][0] == pos) {
          cur_wall.push_back({pos, pre_wall[it][1]});
          ++it;
        } else
          cur_wall.push_back({pos, i});
      }
      pre_wall = cur_wall;
    }
    int minBrick = INT_MAX;
    if (pre_wall.size() == 1 && pre_wall[0][0] == wall_hight) minBrick = wall.size();
    for (const auto& val : pre_wall)
      if (val[1] < minBrick) minBrick = val[0] == wall_hight ? minBrick : val[1];
    return minBrick;
  }
};

int main(void) {
  Solution sln;
  int rtn = sln.leastBricks({{123}, {123}, {123}});
  rtn = sln.leastBricks({{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1}});

  vector<vector<int>> test_sample;

  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < 10000; ++i) test_sample.push_back({i, INT_MAX - i});
    
  std::cout << "time to construct sample: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(
                     std::chrono::system_clock::now() - start)
                     .count()
              << " milliseconds" << std::endl;
  start = std::chrono::system_clock::now();
  rtn = sln.leastBricks(test_sample);

  std::cout << "time to calculate: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(
                   std::chrono::system_clock::now() - start)
                   .count()
            << " milliseconds" << std::endl;
  return 0;
}

