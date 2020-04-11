
#include <map>
#include <vector>
#include <iostream>

using std::map;
using std::vector;

class Solution {
 public:
  int minSteps(const int n) {
    // if (n == 1) return 0;
    vector<map<int, int>> result(n + 1); // map, first: numbers in buffer. secend: steps to get hear.
    result[1].insert({0, 0});
    for (int i = 1; i < n; ++i)
      for (auto iter = result[i].cbegin(); iter != result[i].cend(); ++iter) {
        if (n < i + iter->first) continue;
        if (n == i + iter->second) return iter->second + 1;
        if (i * 2 == n) return iter->second + 2;
        result[i + iter->second].insert({iter->first, iter->second + 1});
        if (n < i * 2) continue;
        result[i * 2].insert({i, iter->second + 2});
      }
    return result[n].begin()->second;
  }
};

int main(void) {
  Solution sln;
  for (int i = 1; i < 1000; ++i) {
    std::cout << sln.minSteps(i) << std::endl;
  }
  return 0;
}

