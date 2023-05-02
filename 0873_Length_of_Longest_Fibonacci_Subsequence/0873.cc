
#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution {
 public:
  int lenLongestFibSubseq(const vector<int>& arr) {
    const unordered_set<int> all_nums{arr.cbegin(), arr.cend()};
    int longest_fib_subseq = 0;
    for (int i = 0; i < arr.size() - 2; ++i)
      for (int j = i + 1; j < arr.size() - 1; ++j) {
        int first_num = arr[i], second_num = arr[j];
        int possible_third_num = first_num + second_num;
        int curr_len = all_nums.count(possible_third_num) != 0 ? 2 : 0;
        while (all_nums.count(possible_third_num) != 0) {
          ++curr_len;
          first_num = second_num;
          second_num = possible_third_num;
          possible_third_num = first_num + second_num;
        }
        longest_fib_subseq = std::max(longest_fib_subseq, curr_len);
      }

    return longest_fib_subseq;
  }
};
