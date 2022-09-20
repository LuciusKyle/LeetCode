
#include <vector>

using std::vector;

class Solution {
 public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> answer_matrix(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
    int answer = 0;
    for (int i = nums1.size() - 1; 0 <= i; --i)
      for (int j = nums2.size() - 1; 0 <= j; --j) {
        if (nums1[i] == nums2[j]) {
          answer_matrix[i][j] = answer_matrix[i + 1][j + 1] + 1;
          if (answer < answer_matrix[i][j])
            answer = answer_matrix[i][j];
        }
      }

    return answer;
  }
};
