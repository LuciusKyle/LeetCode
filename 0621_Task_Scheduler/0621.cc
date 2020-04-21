
#include <memory.h>

#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  // store char in a std::vector? why not using a std::string?
  int leastInterval(const vector<char>& tasks, int n) {
    ++n;
    int counter[26]{0};
    const int all_done[26]{0};
    for (const char ch : tasks) ++counter[ch - 'A'];
    // std::sort(std::begin(counter), std::end(counter), [](int l, int r) -> bool { return r < l; });

    int rtn = 0, executed = 0, executed_tasks = 0;
    do {
      executed = 0;
      for (int i = 0; i < std::end(counter) - std::begin(counter); ++i) {
        if (0 < counter[i]) {
          ++executed_tasks;
          ++executed;
          --counter[i];
          if (executed == n) break;
        }
      }
      rtn += n;
    } while (executed_tasks != tasks.size());
    return rtn - (n - executed);
  }
};

int main(void) {
  Solution sln;
  int ret = sln.leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 2);
  ret = sln.leastInterval(
      {'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'E', 'E', 'F', 'F', 'G',
       'G', 'H', 'H', 'I', 'I', 'J', 'J', 'K', 'K', 'L', 'L', 'M', 'M',
       'N', 'N', 'O', 'O', 'P', 'P', 'Q', 'Q', 'R', 'R', 'S', 'S', 'T',
       'T', 'U', 'U', 'V', 'V', 'W', 'W', 'X', 'X', 'Y', 'Y', 'Z', 'Z'},
      2);
  return 0;
}
