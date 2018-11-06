
#include <assert.h>
#include <fstream>

class Solution {
 public:
  int addDigits(int num) {
    if (num < 10) return num;
    int result = 0;
    while (num > 0) {
      result += num % 10;
      num /= 10;
    }
    return addDigits(result);
  }
};

int main(void) {
  Solution sln;
  assert(2 == sln.addDigits(38));

  std::ofstream file("out.file");
  for (int i = 0; i < 0x1000; ++i) {
    file << i << '\t' << sln.addDigits(i) << '\n';
  }

  return 0;
}