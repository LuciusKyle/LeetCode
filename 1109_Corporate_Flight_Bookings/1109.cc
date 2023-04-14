
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> corpFlightBookings(const vector<vector<int>>& bookings, const int n) {
    vector<int> prefix_answer(n + 1, 0);
    for (const auto& vec : bookings) {
      prefix_answer[vec[0] - 1] += vec[2];
      prefix_answer[vec[1]] -= vec[2];
    }
    for (int i = 1; i < n; ++i)
      prefix_answer[i] += prefix_answer[i - 1];
    prefix_answer.pop_back();
    return prefix_answer;
  }
};
