
#include <iostream>
#include <math.h>

class Solution {
 public:
  bool checkPerfectNumber(int num) {
    if (num == 0 || num == 1) return false;
    int sum = 1;
    for (int i = 2; i <= sqrt(num); i++) {
      if (i == sqrt(num)) {
        double root = 1.0 * sqrt(num);
        double index = i + 0.0;
        if (root == index) sum = sum + i;
      } else if (num % i == 0) {
        sum = sum + i + num / i;
      }
    }
    if (sum == num) return true;
    return false;
  }
};

int main(void) {
  Solution sln;
  for (int i = 0; i < 100000000; ++i) {
    if (sln.checkPerfectNumber(i))
      std::cout << i << std::endl;
  }
  return 0;
}