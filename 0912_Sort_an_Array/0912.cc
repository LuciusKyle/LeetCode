
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <typename T>
void mySort(T* ptr, const int len) {
  if (len == 1 || len == 0) return;
  if (len == 2) {
    if (ptr[1] < ptr[0]) {
      T temp = ptr[0];
      ptr[0] = ptr[1];
      ptr[1] = temp;
    }
    return;
  }
  const T mid_val = ptr[len / 2];  //?
  // ((ptr[0] < ptr[len / 2] && ptr[len - 1] < ptr[0]) || (ptr[0] < ptr[len - 1] && ptr[len / 2] < ptr[0])) ? ptr[0] : ((ptr[len / 2] < ptr[0] && ptr[len - 1] < ptr[len / 2]) || (ptr[len / 2] < ptr[len - 1] && ptr[0] < ptr[len / 2])) ? ptr[len / 2] : ptr[len - 1];
  // std::max(std::min(ptr[0], ptr[len - 1]), std::min(std::max(ptr[0], ptr[len - 1]), ptr[len / 2]));
  T *l_ptr = ptr, *r_ptr = ptr + len - 1;
  do {
    while (*l_ptr < mid_val) ++l_ptr;
    while (mid_val < *r_ptr) --r_ptr;
    if (l_ptr <= r_ptr) {
      T temp_val = *r_ptr;
      *r_ptr = *l_ptr;
      *l_ptr = temp_val;
      ++l_ptr;
      --r_ptr;
    }
  } while (l_ptr <= r_ptr);
  if (ptr < l_ptr)
    mySort(ptr, l_ptr - ptr);
  mySort(l_ptr, len - (l_ptr - ptr));
}

class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    mySort(nums.data(), nums.size());
    return nums;
  }
};

int main(int argc, char* argv[]) {
  vector<int> test_vec = {3, 4, 2, 1};
  Solution sln;
  sln.sortArray(test_vec);

  test_vec.clear();
  for (int i = 1; i < argc; ++i) {
    test_vec.push_back(atoi(argv[i]));
  }
  sln.sortArray(test_vec);
  for (const int val : test_vec)
    cout << val << ' ';
  cout << endl;
  return 0;
}
