#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> result(n + 1);
    for (int i = 1, restart_num = 1; i < n + 1; ++i)
      if (i == restart_num) {
        result[i] = 1;
        restart_num *= 2;
      } else {
        result[i] = result[i - restart_num / 2] + 1;
      }
    return result;
  }
};

// official solution
class Solution_official {
 public:
  vector<int> countBits(int n) {
    vector<int> counts(n + 1);
    // For any number x > 0, if we remove the least significant bit of x, then its bit count will reduce by 1.
    for (int i = 1; i <= n; ++i) {
      uint least_significant_bit = ~(i - 1) & i;
      counts[i] = 1 + counts[i ^ least_significant_bit];
    }
    return counts;
  }
};

int main(int argc, char *argv[]) {
  for (int i = 0; i <= 1026; ++i) {
    int count_ones = 0;
    int num = i;
    while (num != 0) {
      if (num & 1) ++count_ones;
      num = num >> 1;
    }
    cout << i << ":\t\t" << count_ones << "\n";
  }
  return 0;
}