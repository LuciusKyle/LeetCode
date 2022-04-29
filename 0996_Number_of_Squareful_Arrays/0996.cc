
#include <assert.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  Solution() {
    all_perfect_square_.reserve(44723);
    int i = 0;
    do {
      all_perfect_square_.push_back(i * i);
      ++i;
    } while (i * i < 2000000000);
    all_perfect_square_.push_back(i * i);
  }
  int numSquarefulPerms(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    char* vec_snapshot = new char[nums.size() * sizeof(int)];
    memcpy(vec_snapshot, nums.data(), nums.size() * sizeof(int));

    int all_count = 0;
    do {
      bool perfect_square = true;
      for (size_t i = 1; i < nums.size(); ++i) {
        if (!std::binary_search(all_perfect_square_.cbegin(), all_perfect_square_.cend(), nums[i - 1] + nums[i])) {
          perfect_square = false;
          break;
        }
      }
      if (perfect_square) ++all_count;
      std::next_permutation(nums.begin(), nums.end());
    } while (memcmp(vec_snapshot, nums.data(), nums.size() * sizeof(int)));
    delete[] vec_snapshot;
    return all_count;
  }

 private:
  vector<int> all_perfect_square_;
};

int main(void) {
  Solution sln;
  vector test_vec{1, 17, 8};
  int ret = sln.numSquarefulPerms(test_vec);
  assert(2 == ret);
  test_vec = {89, 72, 71, 44, 50, 72, 26, 79, 33, 27, 84};
  ret = sln.numSquarefulPerms(test_vec);
  cout << ret << endl;
  return 0;
  int i = 0;
  do {
    if (i % 1000 == 0) cout << "\n";
    cout << i * i << ",";
    ++i;
  } while (i * i < 2000000000);
  cout << i * i << endl;
}
