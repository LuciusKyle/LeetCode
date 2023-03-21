
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

constexpr int kModulo = 1'000'000'007;

class Solution {
 public:
  int nthMagicalNumber(int n, const int a, const int b) {
    const int common_multiple = leaseCommonMultiple(a, b) % kModulo;
    const int max_step = kModulo / common_multiple;
    int steps = n / number_base_.size();
    int answer = 0;
    while (max_step < steps) {
      answer += max_step * common_multiple;
      answer %= kModulo;
      steps -= max_step;
    }
    answer += steps * common_multiple;
    answer %= kModulo;
    n %= number_base_.size();
    if (n == 0) return answer;
    return (answer + (number_base_[n - 1] % kModulo)) % kModulo;
  }

 private:
  vector<int> number_base_;
  int leaseCommonMultiple(const int a, const int b) {
    number_base_.push_back(std::min(a, b));
    int multiple_a = 1, multiple_b = 1;
    while (multiple_a * a != multiple_b * b) {
      if (multiple_a * a < multiple_b * b)
        ++multiple_a;
      else
        ++multiple_b;
      number_base_.push_back(std::min(multiple_a * a, multiple_b * b));
    }
    return multiple_a * a;
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  sln.nthMagicalNumber(4, 2, 3);
  cout << sln.nthMagicalNumber(1000000000, 39999, 40000) << endl;
  return 0;
}