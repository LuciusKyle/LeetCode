
#include <numeric>
#include <vector>

using std::vector;

class Solution {
 public:
  bool makesquare(const vector<int>& matchsticks) {
    const int all_sum = std::accumulate(matchsticks.cbegin(), matchsticks.cend(), 0);
    if (all_sum % 4 != 0) return false;
    all_sum_ = all_sum;
    all_used_sticks_.resize(1 << matchsticks.size());
    return makeSquare(matchsticks, 0, 0, 0, all_sum / 4);
  }

 private:
  int all_sum_;
  vector<char> all_used_sticks_;
  bool makeSquare(const vector<int>& matchsticks, const int curr_edge, const int start_index, const int used_sticks, const int target) {
    if (all_used_sticks_[used_sticks] != 0) return all_used_sticks_[used_sticks] == 1;
    if (curr_edge == 3) {
      all_used_sticks_[used_sticks] = 1;
      return true;
    }
    for (int i = start_index; i < matchsticks.size(); ++i) {
      if (!(used_sticks & (1 << i)) && matchsticks[i] <= target) {
        if (makeSquare(matchsticks, matchsticks[i] == target ? curr_edge + 1 : curr_edge, matchsticks[i] == target ? 0 : i + 1, used_sticks | 1 << i, matchsticks[i] == target ? all_sum_ / 4 : target - matchsticks[i])) {
          all_used_sticks_[used_sticks] = 1;
          return true;
        }
      }
    }
    all_used_sticks_[used_sticks] = -1;
    return false;
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  sln.makesquare({1, 1, 2, 2, 2});
  return 0;
}
