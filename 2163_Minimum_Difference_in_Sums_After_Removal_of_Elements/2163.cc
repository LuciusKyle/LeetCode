
#include <limits.h>

#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;

class Solution {
 public:
  long long minimumDifference(vector<int>& nums) {
    const int n = nums.size() / 3;
    long long sum_first = 0, sum_second = 0;
    priority_queue<int> first_pq;
    priority_queue<int, vector<int>, std::greater<int>> second_pq;
    for (int i = 0; i < n; ++i) {
      first_pq.push(nums[i]);
      sum_first += nums[i];
      second_pq.push(nums[2 * n + i]);
      sum_second += nums[2 * n + i];
    }
    vector<long long> first_sum_vec;
    first_sum_vec.reserve(n + 1);
    first_sum_vec.push_back(sum_first);
    for (int i = n; i < 2 * n; ++i) {
      first_pq.push(nums[i]);
      sum_first = sum_first + nums[i] - first_pq.top();
      first_pq.pop();
      first_sum_vec.push_back(sum_first);
    }
    long long answer = sum_first - sum_second;
    for (int i = 2 * n - 1; n <= i; --i) {
      second_pq.push(nums[i]);
      sum_second = sum_second + nums[i] - second_pq.top();
      second_pq.pop();
      answer = std::min(answer, first_sum_vec[i - n] - sum_second);
    }
    return answer;
  }
};

int main(int argc, char* argv[]) {
  priority_queue<int> pq;
  pq.push(2);
  pq.push(1);
  pq.push(3);
  cout << pq.top() << endl;
  return 0;
}
