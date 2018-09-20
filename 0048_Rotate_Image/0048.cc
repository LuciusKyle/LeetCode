
#include <functional>
#include <vector>

using std::vector;

class Solution {
 public:
  void rotate(vector<vector<int>> &matrix) {
    const size_t out_edge_length = matrix.size();
    for (size_t j = 0; j < out_edge_length / 2; ++j) {
      const size_t inner_edge_length = out_edge_length - 2 * j;
      for (size_t i = 0; i < inner_edge_length - 1; ++i) {
        sift_element(
            matrix[j][i + j], matrix[i + j][inner_edge_length - 1 + j],
            matrix[inner_edge_length - 1 + j][inner_edge_length - 1 - i + j],
            matrix[inner_edge_length - 1 - i + j][j]);
      }
    }
  }

 private:
  void sift_element(int &a0, int &a1, int &a2, int &a3) const {
    a3 ^= a2;
    a2 ^= a3;
    a3 ^= a2;

    a2 ^= a1;
    a1 ^= a2;
    a2 ^= a1;

    a1 ^= a0;
    a0 ^= a1;
    a1 ^= a0;
  }
};

int main(int argc, char const *argv[]) {
  Solution sln;

  vector<int> row_0{1, 2, 3};
  vector<int> row_1{4, 5, 6};
  vector<int> row_2{7, 8, 9};

  vector<vector<int>> vec{row_0, row_1, row_2};
  sln.rotate(vec);
  return 0;
}
