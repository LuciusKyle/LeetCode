
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> result;
    for (const int asteroid : asteroids) {
      if (asteroid < 0) {
        while (!result.empty() && 0 < result.back() && result.back() < (asteroid * -1)) result.pop_back();
        if (result.empty() || result.back() < 0)
          result.push_back(asteroid);
        else if (result.back() == (asteroid * -1))
          result.pop_back();
      } else
        result.push_back(asteroid);
    }
    return result;
  }
};
