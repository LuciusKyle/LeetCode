
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  vector<vector<int>> kClosest(const vector<vector<int>>& points, int k) {
#if 202002 <= __cplusplus
    std::multiset<std::pair<int, int>, decltype([](const std::pair<int, int>& _x, const std::pair<int, int>& _y) -> bool { return (_x.first * _x.first + _x.second * _x.second) < (_y.first * _y.first + _y.second * _y.second); })> points_set;
#else
    auto cmp = [](const std::pair<int, int>& _x, const std::pair<int, int>& _y) -> bool { return (_x.first * _x.first + _x.second * _x.second) < (_y.first * _y.first + _y.second * _y.second); };
    std::multiset<std::pair<int, int>, decltype(cmp)> points_set(cmp);
#endif
    for (const auto& point : points) {
      points_set.emplace(point[0], point[1]);
      if (k < points_set.size()) points_set.erase(--points_set.end());
    }
    vector<vector<int>> ret;
    for (auto iter = points_set.cbegin(); iter != points_set.cend(); ++iter) {
      ret.push_back(vector<int>{iter->first, iter->second});
    }
    return ret;
  }
};

int main(void) {
  cout << "__cplusplus: " << __cplusplus << endl;
  return 0;
}
