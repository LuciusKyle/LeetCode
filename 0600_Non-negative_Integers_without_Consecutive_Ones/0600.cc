
#include <assert.h>
#include <limits.h>

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  int findIntegers(const int n) {
    return n;
  }
};

int main(int argc, char *argv[]) {
  Solution sln;
  int rtn = sln.findIntegers(5);
  assert(rtn == 5);
  return 0;

  int consecutive_ones_count = 0;
  bool got_a_one = false, got_consecutive_ones = false;
  int previous_output = 0;
  for (int i = 0; i < 1000000000; ++i) {
    int num = i;
    got_a_one = false, got_consecutive_ones = false;
    while (num != 0) {
      if (0x1 & num) {
        if (got_a_one) {
          got_consecutive_ones = true;
          break;
        } else
          got_a_one = true;
      } else {
        got_a_one = false;
      }
      num = num >> 1;
    }
    if (got_consecutive_ones) ++consecutive_ones_count;
    if (previous_output != i + 1 - consecutive_ones_count) {
      cout << i << ":\t\t" << i + 1 - consecutive_ones_count << "\n";
      previous_output = i + 1 - consecutive_ones_count;
    }
  }
  cout << endl;
  return 0;
}
