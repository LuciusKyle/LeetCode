
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<bool> kidsWithCandies(const vector<int>& candies, int extraCandies) {
    const int max_candy = *std::max_element(candies.cbegin(), candies.cend());
    vector<bool> answer;
    answer.reserve(candies.size());
    for (const int c : candies)
      answer.push_back(max_candy <= c + extraCandies);
    return answer;
  }
};
