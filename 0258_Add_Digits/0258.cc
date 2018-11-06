
#include <assert.h>
#include <fstream>

class Solution {
 public:
  int addDigits(int num) { return (num - 1) % 9 + 1; }
};

int main(void) {
  Solution sln;
  assert(2 == sln.addDigits(38));

  return 0;
}