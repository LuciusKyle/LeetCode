
#include <assert.h>

#include <vector>

using std::vector;

class Solution {
 public:
  long long minimumReplacement(const vector<int>& nums) {
    long long answer = 0;
    for (int i = nums.size() - 1, curr_min = nums.back(); 0 <= i; --i) {
      if (curr_min < nums[i]) {
        const int answer_increament = nums[i] / curr_min + (nums[i] % curr_min != 0) - 1;
        answer += answer_increament;
        curr_min = nums[i] / (answer_increament + 1);
      }
      curr_min = std::min(curr_min, nums[i]);
    }
    return answer;
  }
};

int main(int argc, char *argv[]) {
  Solution sln;
  assert(6 == sln.minimumReplacement({12, 9, 7, 6, 17, 19, 21}));
  assert(10 == sln.minimumReplacement({7, 6, 15, 6, 11, 14, 10}));
  return 0;
}
