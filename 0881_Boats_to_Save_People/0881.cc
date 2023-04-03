
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    std::sort(people.begin(), people.end());
    int result = 0, l_index = 0, r_index = people.size() - 1;
    while (l_index < r_index) {
      if (people[l_index] + people[r_index] <= limit)
        ++l_index;
      --r_index;
      ++result;
    }
    return l_index == r_index ? result + 1 : result;
  }
};
