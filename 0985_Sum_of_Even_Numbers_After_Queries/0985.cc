
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> sumEvenAfterQueries(vector<int>& nums, const vector<vector<int>>& queries) {
    int sum_of_even = 0;
    for (const int num : nums)
      if ((num & 1) == 0) sum_of_even += num;

    vector<int> answers;
    answers.reserve(queries.size());
    for (const auto& query : queries) {
      const int original_num = nums[query[1]], new_num = original_num + query[0];
      nums[query[1]] = new_num;
      if ((original_num & 1) == 0)
        if ((new_num & 1) == 0)
          sum_of_even += query[0];
        else
          sum_of_even -= original_num;
      else if ((new_num & 1) == 0)
        sum_of_even += new_num;
      answers.push_back(sum_of_even);
    }
    return answers;
  }
};

int main(void) {
  vector<int> test_vec = {1,2,3,4};
  vector<vector<int>> test_queries = {{1,0},{-3,1},{-4,0},{2,3}};
  Solution sln;
  sln.sumEvenAfterQueries(test_vec, test_queries);
  return 0;
}
