
#include <math.h>
#include <stdio.h>
#include <string.h>

#include <vector>

using std::vector;



class Solution {
 public:
  int minMoves2(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    const int target = nums[nums.size() / 2];
    int result = 0;
    for (const int n : nums) result += abs(n - target);
    return result;
  }
};

int main(int argc, char *argv[]) {
  if (argc == 1) return -1;
  const double num = strtod(argv[1], &(argv[strlen(argv[1])]));
  printf("%f\t round is: %f, integer is: %d", num, round(num), int(round(num)));
  return 0;
}