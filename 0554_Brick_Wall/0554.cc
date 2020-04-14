
#include <limits.h>

#include <chrono>
#include <iostream>
#include <unordered_map>
#include <numeric>
#include <vector>

using std::vector;
using std::unordered_map;

class Solution {
 public:
  int leastBricks(const vector<vector<int>>& wall) {
    unordered_map<int, int> brick_edge_count;
    for (const auto& vec : wall) {
      int pos = 0;
      for (int i = 0; i < vec.size() - 1; ++i) {
        pos += vec[i];
        if (brick_edge_count.count(pos)) ++brick_edge_count.at(pos);
        else brick_edge_count.insert({pos, 1});
      }
    }
    int most_common = 0;
    for (auto iter = brick_edge_count.cbegin(); iter != brick_edge_count.cend(); ++iter)
      if (most_common < iter->second) most_common = iter->second;
    return wall.size() - most_common;
  }
};

int main(void) {
  Solution sln;
  int rtn = sln.leastBricks({{123}, {123}, {123}});
  rtn = sln.leastBricks({{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1}});

  vector<vector<int>> test_sample;

  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < 1000000; ++i) test_sample.push_back({i, INT_MAX - i});
    
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

