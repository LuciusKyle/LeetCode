
#include <ctype.h>

#include <vector>

using std::vector;

class Solution {
 public:
  void duplicateZeros(vector<int>& arr) {
    const auto arr_copy = arr;
    for (size_t i = 0, j = 0; j < arr.size(); ++j, ++i) {
      arr[j] = arr_copy[i];
      if (j + 1 < arr_copy.size() && arr_copy[i] == 0)
        arr[++j] = arr_copy[i];
    }
  }
};

int main(int argc, char* argv[]) {
  vector<int> test_vec{1, 0, 2, 3, 0, 4, 5, 0};
  Solution sln;
  sln.duplicateZeros(test_vec);

  test_vec = {1, 2, 3};
  sln.duplicateZeros(test_vec);
  return 0;
}
