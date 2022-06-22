
#include <assert.h>
#include <limits.h>

#include <algorithm>
#include <chrono>
#include <iostream>
#include <set>
#include <thread>
#include <vector>

using std::multiset;
using std::vector;

class Solution {
 public:
  int findKthLargest(const vector<int>& nums, int k) {
    multiset<int> k_nums;
    k_nums.insert(INT_MIN);
    for (const int num : nums) {
      if (*k_nums.cbegin() <= num) k_nums.insert(num);
      if (k_nums.size() > k) k_nums.erase(k_nums.begin());
    }
    return *k_nums.cbegin();
  }
};

int main(void) {
  Solution sln;

  auto start = std::chrono::system_clock::now();
  vector<int> test_vec;
  FILE* fp = fopen("testcase1.txt", "rb");
  char* buf = new char[2 * 1024 * 1024];
  const size_t read_size = fread(buf, 1, 2 * 1024 * 1024, fp);
  assert(read_size < 2 * 1024 * 1024);
  for (size_t i = 1; i <= read_size; ++i)
    if ((!('0' <= buf[i - 1] && buf[i - 1] <= '9')) && ('0' <= buf[i] && buf[i] <= '9')) test_vec.push_back(atoi(buf + i));
  fclose(fp);
  delete[] buf;
  const int test_k = test_vec.back();
  test_vec.pop_back();
  std::cout << "time to prepare data: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << " milliseconds" << std::endl;
  start = std::chrono::system_clock::now();
  int rtn = sln.findKthLargest(test_vec, test_k);
  std::cout << "time to calculate: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << " milliseconds" << std::endl;

  return 0;
}
