
#include <assert.h>
#include <limits.h>

#include <vector>

using std::vector;

class Solution {
 public:
  int candy(const vector<int>& ratings) {
    vector<int> result;
    result.reserve(ratings.size());
    for (int i = 0, pre_rating = INT_MAX; i < ratings.size(); ++i) {
      result.push_back(ratings[i] <= pre_rating ? 1 : (result.back() + 1));
      pre_rating = ratings[i];
    }
    int all_candies = 0;
    for (int i = ratings.size() - 1, pre_rating = INT_MAX; 0 <= i; --i) {
      const int curr_candy = ratings[i] <= pre_rating ? 1 : (result[i + 1] + 1);
      result[i] = std::max(curr_candy, result[i]);
      all_candies += result[i];
      pre_rating = ratings[i];
    }
    return all_candies;
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  assert(5 == sln.candy({1, 0, 2}));
  assert(4 == sln.candy({1, 1, 2}));
  assert(4 == sln.candy({1, 2, 2}));
  assert(7 == sln.candy({1, 3, 2, 2, 1}));
  return 0;
}
