
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
    int buckets[16] = {0};
    for (const int num : arr) {
      int count_1 = 0;
      for (int i = 0; i < 15; ++i)
        if ((1 << i) & num) ++count_1;
      ++buckets[count_1];
    }
    int* buckets_ptr[16] = {nullptr};
    vector<int> answer(arr.size());
    for (int i = 0, pre_count_sum = 0; i < 16; ++i) {
      buckets_ptr[i] = answer.data() + pre_count_sum;
      pre_count_sum += buckets[i];
    }
    for (const int num : arr) {
      int count_1 = 0;
      for (int i = 0; i < 15; ++i)
        if ((1 << i) & num) ++count_1;
      *buckets_ptr[count_1] = num;
      ++buckets_ptr[count_1];
    }
    return answer;
  }
};


// __builtin_popcount() ???
class Solution___builtin_popcount {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
    int buckets[16] = {0};
    for (const int num : arr)
      ++buckets[__builtin_popcount(num)];
    int* buckets_ptr[16] = {nullptr};
    vector<int> answer(arr.size());
    for (int i = 0, pre_count_sum = 0; i < 16; ++i) {
      buckets_ptr[i] = answer.data() + pre_count_sum;
      pre_count_sum += buckets[i];
    }
    for (const int num : arr) {
      const int count_1 = __builtin_popcount(num);
      *buckets_ptr[count_1] = num;
      ++buckets_ptr[count_1];
    }
    return answer;
  }
};


int main(int argc, char* argv[]) {
  vector<int> test_vec = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  Solution sln;
  sln.sortByBits(test_vec);
  return 0;
}
