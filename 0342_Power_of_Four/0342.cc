
#include <assert.h>
#include <limits.h>
#include <math.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <set>

using std::cout;
using std::endl;

constexpr std::array kAllPowerOfFour{1, 4, 16, 64, 256, 1024, 4096, 16384, 65536, 262144, 1048576, 4194304, 16777216, 67108864, 268435456, 1073741824};
const std::set kAllPowerOfFourSet(kAllPowerOfFour.cbegin(), kAllPowerOfFour.cend());

class Solution {
 public:
  bool isPowerOfFour(int num) { return kAllPowerOfFourSet.count(num); }
};

int main(int argc, char const *argv[]) {
  for (int i = -4; i < 100; ++i) {
    cout << i << ":\t" << pow(4, i) << "\n";
    if (INT_MAX < pow(4, i)) break;
  }
  cout << endl;
  return 0;

  Solution sln;
  assert(sln.isPowerOfFour(1));
  assert(sln.isPowerOfFour(4));
  assert(sln.isPowerOfFour(16));
  assert(!sln.isPowerOfFour(2));
  assert(!sln.isPowerOfFour(1234567));
  return 0;
}
