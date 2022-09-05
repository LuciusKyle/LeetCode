
#include <limits.h>

#include <vector>

using std::vector;

class Solution {
 public:
  int reductionOperations(const vector<int>& nums) {
    vector<int> num_coll(50001);
    for (const int num : nums) ++num_coll[num];

    int answer = 0;
    for (int i = 50000, curr_num_count = 0; 0 <= i; --i)
      if (num_coll[i] != 0) {
        answer += curr_num_count;
        curr_num_count += num_coll[i];
      }

    return answer;
  }
};

int main(void) {
  vector test_vec{7, 9, 10, 8, 6, 4, 1, 5, 2, 3};
  Solution sln;
  sln.reductionOperations(test_vec);
  return 0;
}