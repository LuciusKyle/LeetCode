
#include <math.h>

#include <array>
#include <iostream>
#include <numeric>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> numsSameConsecDiff(const int n, const int k) {
    if (k == 0) {
      vector<int> answer;
      for (int digit = 1; digit < 10; ++digit) {
        int num = digit;
        for (int i = 0; i < n - 1; ++i)
          num = num * 10 + digit;
        answer.push_back(num);
      }
      return answer;
    }
    vector<int> next_num, current_num{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 1; i < n; ++i) {
      for (const int num : current_num) {
        const int last_digit = num % 10;
        if (last_digit + k < 10)
          next_num.push_back(num * 10 + last_digit + k);
        if (-1 < last_digit - k)
          next_num.push_back(num * 10 + last_digit - k);
      }
      current_num.swap(next_num);
      next_num.clear();
    }
    return current_num;
  }
};

int main(void) {
  Solution sln;
  sln.numsSameConsecDiff(2, 1);

  return 0;

  for (int n = 2; n <= 9; ++n)
    for (int k = 0; k <= 9; ++k)
      std::cout << n << "\n"
                << k << "\n";
  std::cout << std::endl;
  return 0;
}