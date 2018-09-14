
#include <cmath>
#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    int i, j, k, diff, sum, minSum;
    int min = 99999999;
    int len = nums.size();

    priority_queue<int> q;
    for (i = 0; i < len; i++) q.push(nums[i]);

    vector<int> a;
    for (i = 0; i < len; i++) {
      a.push_back(q.top());
      q.pop();
    }  // now a is in descending order

    for (i = 0; i < len; i++) {
      j = i + 1;
      k = len - 1;
      while (j < k) {
        sum = a[i] + a[j] + a[k];
        diff = sum - target;
        if (diff == 0)
          return sum;
        else if (diff > 0)
          j++;
        else
          k--;
        if (abs(diff) < min) {
          minSum = sum;
          min = abs(diff);
        }
      }
    }
    return minSum;
  }
};