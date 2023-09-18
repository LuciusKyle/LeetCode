
#include <queue>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> kWeakestRows(const vector<vector<int>>& mat, int k) {
    const int row_size = mat.size(), column_size = mat[0].size();
    std::priority_queue<std::pair<int, int>> pq;
    for (int row = 0; row < mat.size(); ++row) {
      int l_index = 0, r_index = column_size - 1;
      while (l_index + 1 < r_index) {
        const int mid_index = (l_index + r_index) / 2;
        if (mat[row][mid_index] == 1)
          l_index = mid_index;
        else
          r_index = mid_index;
      }
      int addition = 0;
      if (mat[row][l_index] == 1 && mat[row][r_index] == 0)
        addition = 1;
      else if (mat[row][l_index] == 1 && mat[row][r_index] == 1)
        addition = 2;
      pq.emplace(l_index + addition, row);
      if (k < pq.size()) pq.pop();
    }
    vector<int> answer(k);
    for (int i = k - 1; 0 <= i; --i) {
      answer[i] = pq.top().second;
      pq.pop();
    }
    return answer;
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  sln.kWeakestRows({{1, 1, 0, 0, 0}, {1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 1, 1, 1, 1}}, 3);
  sln.kWeakestRows({{1, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 0}}, 2);
  return 0;
}
