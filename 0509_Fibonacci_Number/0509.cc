
#include <iostream>
#include <array>

constexpr int fib_nums[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040};

class Solution {
 public:
  int fib(int N) { return fib_nums[N]; }
};

int main(void) {
  Solution sln;
  for (int i = 0; i <= 30; ++i) {
    std::cout << sln.fib(i) << ", ";
  }
  std::cout << std::endl;
  return 0;
}
