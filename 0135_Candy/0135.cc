
#include <assert.h>
#include <vector>

using std::vector;

class Solution {
 public:
  int candy(const vector<int>& ratings) {
    int decrease_streak = 0;
    int rtn = ratings.empty() ? 0 : 1;
    int cur_candy = 1;
    for (size_t i = 1; i < ratings.size(); ++i) {
      if (ratings[i] < ratings[i - 1]) {
        ++decrease_streak;
        if (decrease_streak == 1) cur_candy = 1;
      } else if (ratings[i] > ratings[i - 1]) {
        decrease_streak = 0;
        cur_candy += 1;
      }
      rtn += (cur_candy + decrease_streak);
    }
    if (ratings.size() > 1 && ratings[ratings.size() - 1] == ratings[ratings.size() - 2] && cur_candy != 1) {
      rtn -= (cur_candy - 1);
    }
    return rtn;
  }
};

int main(void) {
  Solution sln;
  assert(5 == sln.candy({1, 0, 2}));
  assert(4 == sln.candy({1, 1, 2}));
  assert(4 == sln.candy({1, 2, 2}));
  assert(7 == sln.candy({1, 3, 2, 2, 1}));
  return 0;
}

