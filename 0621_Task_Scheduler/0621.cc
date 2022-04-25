
#include <assert.h>
#include <memory.h>

#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  // store char in a std::vector? why not using a std::string?
  int leastInterval(const vector<char>& tasks, const int n) {
    int counter[26]{0};
    const int all_done[26]{0};
    for (const char ch : tasks) ++counter[ch - 'A'];

    int tasks_count = 0;
    int idle_count = 0;
    do {
      std::sort(std::begin(counter), std::end(counter), [](const int l, const int r) -> bool { return r < l; });
      tasks_count += idle_count;
      idle_count = 0;
      for (int i = 0, cur_index = 0; i <= n; ++i) {
        if (cur_index != 26 && counter[cur_index] != 0) {
          --counter[cur_index];
          ++tasks_count;
        } else {
          idle_count = n - i + 1;
          break;
        }
        ++cur_index;
      }
    } while (memcmp(counter, all_done, sizeof(all_done)));
    return tasks_count;
  }
};

int main(void) {
  Solution sln;
  int ret = 0;
  ret = sln.leastInterval({'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C', 'D', 'D', 'E'}, 2);
  assert(ret == 12);
  ret = sln.leastInterval({'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}, 29);
  assert(ret == 31);
  ret = sln.leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 2);
  assert(ret == 8);
  ret = sln.leastInterval({'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'E', 'E', 'F', 'F', 'G', 'G', 'H', 'H', 'I', 'I', 'J', 'J', 'K', 'K', 'L', 'L', 'M', 'M', 'N', 'N', 'O', 'O', 'P', 'P', 'Q', 'Q', 'R', 'R', 'S', 'S', 'T', 'T', 'U', 'U', 'V', 'V', 'W', 'W', 'X', 'X', 'Y', 'Y', 'Z', 'Z'}, 2);
  assert(ret == 52);
  return 0;
}
