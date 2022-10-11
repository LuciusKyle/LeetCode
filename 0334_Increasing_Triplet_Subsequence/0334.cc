
#include <limits.h>

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int min_val = INT_MAX, second_min = INT_MAX;
    for (const int num : nums)
      if (num <= min_val)
        min_val = num;
      else if (num <= second_min)
        second_min = num;
      else
        return true;
    return false;
  }
};

int main(int argc, char* argv[]) {
  vector<int> test_vec;
  for (int i = 1; i < argc; ++i) {
    test_vec.push_back(atoi(argv[i]));
  }
  Solution sln;
  cout << (sln.increasingTriplet(test_vec) ? "true" : "false") << endl;
  return 0;
}