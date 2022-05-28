
#include <limits.h>

#include <iostream>
#include <vector>
#include <thread>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    nums.push_back(-1);
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] != i && nums[i] != -1) {
        const int correct_index = nums[i];
        nums[i] ^= nums[correct_index];
        nums[correct_index] ^= nums[i];
        nums[i] ^= nums[correct_index];
      }
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] == -1) return i;
    return int(nums.size());
  }
};

constexpr int kTestNumber = 1099;

int main(int argc, char* argv[]) {
  Solution sln;
  vector<int> test_vec{9, 6, 4, 2, 3, 5, 7, 0, 1};
  int rtn = sln.missingNumber(test_vec);


  int output = 0;
  const int missing_num = argc == 2 ? atoi(argv[1]) : 0;
  for (int i = 0; i < kTestNumber; ++i) {
    if (i != missing_num)
      output ^= i;
    cout << i << ":\t" << output << "\n";
  }
  int target = kTestNumber;
  switch (kTestNumber % 4) {
    case 0:
      // do nothing;
      break;
    case 1:
      target = 1;
      break;
    case 2:
      target = kTestNumber + 1;
      break;
    case 3:
      target = 0;
      break;
    default:
      abort();
      break;
  }
  cout << "missing number: " << missing_num << ". output ^ target: " << (output ^ target) << endl;
  return 0;
}