
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// beats 30%.
class Solution {
 public:
  int earliestFullBloom(const vector<int>& plantTime, const vector<int>& growTime) {
    const int n = plantTime.size();
    vector<std::pair<int, int>> plantTime_growTime_vec;
    plantTime_growTime_vec.reserve(n);
    for (int i = 0; i < plantTime.size(); ++i)
      plantTime_growTime_vec.emplace_back(plantTime[i], growTime[i]);
    std::sort(plantTime_growTime_vec.begin(), plantTime_growTime_vec.end(), [](const std::pair<int, int>& _x, const std::pair<int, int>& _y) -> bool { if (_y.second < _x.second) return true; else if (_x.second < _y.second) return false; else return _y.first < _x.first; });

    int result = 0;
    int total_plant_time = 0;
    for (int i = 0; i < n; ++i) {
      total_plant_time += plantTime_growTime_vec[i].first;
      if (result < total_plant_time + plantTime_growTime_vec[i].second)
        result = total_plant_time + plantTime_growTime_vec[i].second;
    }
    return result;
  }
};

// official solution
class Solution_official {
 public:
  int earliestFullBloom(const vector<int>& plantTime, const vector<int>& growTime) {
    vector<int> indices(plantTime.size());
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(),
         [&](int i, int j) { return growTime[i] > growTime[j]; });
    int result = 0, curPlantTime = 0;
    for (int i : indices) {
      curPlantTime += plantTime[i];
      result = std::max(result, curPlantTime + growTime[i]);
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<int> plantTime = {27, 5, 24, 17, 27, 4, 23, 16, 6, 26, 13, 17, 21, 3, 9, 10, 28, 26, 4, 10, 28, 2}, growTime = {26, 9, 14, 17, 6, 14, 23, 24, 11, 6, 27, 14, 13, 1, 15, 5, 12, 15, 23, 27, 28, 12};
  Solution sln;
  int result = sln.earliestFullBloom(plantTime, growTime);
  std::cout << result << std::endl;
  return 0;
}