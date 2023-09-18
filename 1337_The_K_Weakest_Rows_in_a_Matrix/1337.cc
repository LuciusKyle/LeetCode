
#include <queue>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> kWeakestRows(const vector<vector<int>>& mat, int k) {
    std::pair<int, int> count_index;
    std::priority_queue<decltype(count_index) /*, std::vector<decltype(count_index)>, decltype([](const decltype(count_index) &x_, const decltype(count_index) &y_) -> bool { return x_.first > y_.first ? true : (x_.second > y_.second); })*/> pq;
    for (int row = 0; row < mat.size(); ++row) {
      count_index = {0, row};
      for (const int num : mat[row])
        count_index.first += num;
      pq.push(count_index);
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
