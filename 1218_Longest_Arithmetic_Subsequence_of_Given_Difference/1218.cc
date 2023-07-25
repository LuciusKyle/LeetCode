
#include <map>
#include <vector>

using std::vector;

class Solution {
 public:
  int longestSubsequence(const vector<int>& arr, const int difference) {
    int dict[3 * 10'000 + 1] = {[0 ... (3 * 10'000)] = -1};
    vector<int> answer_dict(arr.size());
    int max_answer = -1;
    for (int i = arr.size() - 1; 0 <= i; --i) {
      const int next_number = arr[i] + difference + 10'000;
      answer_dict[i] = (0 < next_number && dict[next_number] != -1) ? answer_dict[dict[next_number]] + 1 : 1;
      max_answer = std::max(answer_dict[i], max_answer);
      dict[arr[i] + 10'000] = i;
    }
    return max_answer;
  }
};
