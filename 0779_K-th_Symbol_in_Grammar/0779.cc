
class Solution {
 public:
  int kthGrammar(int n, int k) {
    if (n == 1) return 0;
    const int pre_row_num = kthGrammar(n - 1, (k + 1) / 2);
    const int answer_matrix[][2] = {{1, 0}, {0, 1}};
    // pre_row_num == 0, k % 2 == 1, answer is 0
    //                   k % 2 == 0, answer is 1
    // pre_row_num == 1, k % 2 == 1, answer is 1
    //                   k % 2 == 0, answer is 0
    return answer_matrix[pre_row_num][k % 2];
  }
};
