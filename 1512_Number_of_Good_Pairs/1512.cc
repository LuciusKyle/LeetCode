
#include <array>
#include <vector>

using std::vector;

constexpr std::array<int, 101> createAnswerDict() {
  std::array<int, 101> answer{0, 0, 1};
  for (int i = 2, num = 1; i < answer.size(); ++i) {
    answer[i] = num;
    num += i;
  }
  return answer;
}
constexpr std::array<int, 101> kAnswerDict = createAnswerDict();

class Solution {
 public:
  int numIdenticalPairs(vector<int>& nums) {
    int num_dict[101] = {0};
    for (const int num : nums)
      ++num_dict[num];
    int result = 0;
    for (const int num_count : num_dict)
      result += kAnswerDict[num_count];
    return result;
  }
};
