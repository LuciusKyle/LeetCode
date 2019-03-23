
#include <vector>

using std::vector;

// my answer. require extra space.
class Solution {
 public:
  vector<int> sortArrayByParity(const vector<int>& A) {
    vector<int> rtn = A;
    size_t odd_num_index = 0;
    size_t even_num_index = A.size() - 1;
    for (const auto num : A)
      if ((num & 0x1) == 0)
        rtn[odd_num_index++] = num;
      else
        rtn[even_num_index--] = num;
    return rtn;
  }
};

// my answer. don't require extra space.
class Solution2 {
 public:
  vector<int> sortArrayByParity(vector<int>& A) {
    size_t even_count = 0;
    for (size_t i = 0; i < A.size(); ++i)
      if ((A[i - even_count] & 0x1) == 1 &&
          (i - even_count) != (A.size() - even_count - 1)) {
        A[i - even_count] ^= A[A.size() - even_count - 1];
        A[A.size() - even_count - 1] ^= A[i - even_count];
        A[i - even_count] ^= A[A.size() - even_count - 1];
        ++even_count;
      }
    return A;
  }
};

int main(void) {
  Solution sln;
  auto rtn = sln.sortArrayByParity({0, 1});

  return 0;
}
