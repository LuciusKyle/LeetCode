#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    bool carry = false;
    ++digits.back();
    for (auto r_iter = digits.rbegin(); r_iter != digits.rend(); ++r_iter) {
      if (carry) ++(*r_iter);
      if (*r_iter >= 10) {
        carry = true;
        if (r_iter != digits.rend() - 1) *r_iter -= 10;
      } else
        carry = false;
    }
    if (digits.front() >= 10) {
      vector<int> rtn(digits.size() + 1, 0);
      rtn[0] = digits.front() / 10;
      rtn[1] = digits.front() % 10;
      for (size_t i = 1; i < digits.size(); ++i) rtn[i + 1] = digits[i];
      return rtn;
    } else
      return vector<int>(digits);
  }
};

int main(void) {
  Solution sln;
  vector<int> test_vec{9, 4};
  auto rtn = sln.plusOne(test_vec);

  return 0;
}