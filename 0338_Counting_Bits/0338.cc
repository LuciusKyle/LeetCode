#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> result;
    result.reserve(n + 1);
    for (int i = 0; i <= n; ++i) {
      int count_ones = 0;
      int num = i;
      while (num != 0) {
        if (num & 1) ++count_ones;
        num = num >> 1;
      }
      result.push_back(count_ones);
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  for (int i = 0; i <= 100000; ++i) {
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