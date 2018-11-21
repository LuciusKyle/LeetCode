
#include <assert.h>
#include <unordered_set>
#include <vector>

using std::vector;

class Solution {
 public:
  bool isHappy(const int n) {
    std::unordered_set<int> nums;
    int num = n;
    while (num != 1)
      if (nums.insert(num).second)
        num = HappyNumberTransform(num);
      else
        return false;

    return true;
  }

 private:
  int HappyNumberTransform(int n) {
    int rtn = 0;
    while (n != 0) {
      rtn += (n % 10) * (n % 10);
      n /= 10;
    }
    return rtn;
  }
};

int main(void) {
  Solution sln;
  assert(sln.isHappy(19));
  return 0;
}
