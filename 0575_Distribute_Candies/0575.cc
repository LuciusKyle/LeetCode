
#include <vector>
#include <unordered_set>

using std::vector;

class Solution {
 public:
  int distributeCandies(vector<int>& candies) {
    std::unordered_set<int> candies_set;
    for (const int candy : candies) candies_set.insert(candy);
    return candies.size() / 2  < candies_set.size() ? candies.size() / 2 : candies_set.size();
  }
};
