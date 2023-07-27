
#include <algorithm>
#include <numeric>
#include <vector>

using std::vector;

class Solution {
 public:
  long long maxRunTime(int n, vector<int>& batteries) {
    std::sort(batteries.begin(), batteries.end());
    const int start_pos = batteries.size() - n, batteries_count = batteries.size();
    long long battery_left = std::accumulate(batteries.cbegin(), batteries.cbegin() + (batteries_count - n), 0ll);
    int current_bottle_neck = batteries[start_pos], curr_pos = -1;
    for (int i = start_pos + 1; i < batteries_count; ++i) {
      if (battery_left < (batteries[i] - current_bottle_neck) * (i - start_pos)) {
        // a little bit problem, (batteries[i] - current_bottle_neck) * (i - start_pos) could overflow signed int.
        curr_pos = i;
        break;
      }
      battery_left -= ((batteries[i] - current_bottle_neck) * (i - start_pos));
      current_bottle_neck = batteries[i];
    }
    return battery_left / ((curr_pos == -1 ? int(batteries.size()) : curr_pos) - start_pos) + current_bottle_neck;
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  vector<int> test_vec{3, 3, 3};
  sln.maxRunTime(2, test_vec);
  test_vec = {1, 1, 1, 1};
  sln.maxRunTime(2, test_vec);
  return 0;
}
