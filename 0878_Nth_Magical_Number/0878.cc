
#include <vector>

using std::vector;

class Solution {
 public:
  int nthMagicalNumber(int n, const int a, const int b) {
    const int common_multiple = leaseCommonMultiple(a, b);
    int answer = (n / int(number_base_.size())) * common_multiple;
    n %= number_base_.size();
    if (n == 0) return answer;
    return answer + number_base_[n - 1];
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
  return 0;
}