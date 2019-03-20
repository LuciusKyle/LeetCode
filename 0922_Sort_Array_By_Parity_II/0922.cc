
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& A) {
    size_t odd_num_index = 0;
    size_t even_num_index = 1;
    while (odd_num_index < A.size() && even_num_index < A.size()) {
      while ((A[odd_num_index] & 0x1) == 0 && odd_num_index < A.size())
        odd_num_index += 2;
      while ((A[even_num_index] & 0x1) == 1 && even_num_index < A.size())
        even_num_index += 2;
      if ((A[odd_num_index] & 0x1) != 0 && (A[even_num_index] & 0x1) != 1) {
        A[odd_num_index] ^= A[even_num_index];
        A[even_num_index] ^= A[odd_num_index];
        A[odd_num_index] ^= A[even_num_index];
      }
    }
    return A;
  }
};

int main(void) {
  Solution sln;
  vector<int> test{4, 2, 5, 7};
  auto rtn = sln.sortArrayByParityII(test);
  return 0;
}