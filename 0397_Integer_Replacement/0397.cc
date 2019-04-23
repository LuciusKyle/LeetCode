
#include <limits.h>
#include <algorithm>
#include <unordered_map>

class Solution {
 public:
  int integerReplacement(int n) {
    if (n == 1) return 0;
    if (dp_data_.count(n) != 0) return dp_data_.at(n);
    const int rtn = (n & 1) == 1 ? (2 + std::min(integerReplacement(n / 2), integerReplacement(n / 2 + 1))) : (1 + integerReplacement(n / 2));
    dp_data_.insert({n, rtn});
    return rtn;
  }

 private:
  std::unordered_map<int, int> dp_data_;
};

int main(void) {
  Solution sln;
  int rtn = sln.integerReplacement(7);
  rtn = sln.integerReplacement(INT_MAX);
  return 0;
}