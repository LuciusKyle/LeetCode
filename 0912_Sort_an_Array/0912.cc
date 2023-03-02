
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    myQuickSort(nums.data(), nums.size());
    return nums;
  }

 private:
  template <typename T>
  void myQuickSort(T* ptr, const int len) const {
    if (len == 1 || len == 0) return;
    if (len == 2) {
      if (ptr[1] < ptr[0]) {
        T temp = ptr[0];
        ptr[0] = ptr[1];
        ptr[1] = temp;
      }
      return;
    }
    const T mid_val = std::max(std::min(ptr[0], ptr[len - 1]), std::min(std::max(ptr[0], ptr[len - 1]), ptr[len / 2]));
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
    myQuickSort(ptr, l_ptr - ptr);
    myQuickSort(l_ptr, len - (l_ptr - ptr));
  }
};

int main(int argc, char* argv[]) {
  vector<int> test_vec = {-74, 48, -20, 2, 10, -84, -5, -9, 11, -24, -91, 2, -71, 64, 63, 80, 28, -30, -58, -11, -44, -87, -22, 54, -74, -10, -55, -28, -46, 29, 10, 50, -72, 34, 26, 25, 8, 51, 13, 30, 35, -8, 50, 65, -6, 16, -2, 21, -78, 35, -13, 14, 23, -3, 26, -90, 86, 25, -56, 91, -13, 92, -25, 37, 57, -20, -69, 98, 95, 45, 47, 29, 86, -28, 73, -44, -46, 65, -84, -96, -24, -12, 72, -68, 93, 57, 92, 52, -45, -2, 85, -63, 56, 55, 12, -85, 77, -39};
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
