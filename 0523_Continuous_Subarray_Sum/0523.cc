
#include <assert.h>
#include <stdio.h>

#include <chrono>
#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
 public:
  bool checkSubarraySum(const vector<int>& nums, int k) {
    const int nums_size = nums.size();
    if (nums_size < 2) return false;

    unordered_map<int, int> prefix_sum;
    prefix_sum.reserve(nums_size + 1 + 16);  // (nums_size + 1) is OK!
    prefix_sum.insert({0, 0});
    prefix_sum.insert({nums[0] % k, 1});
    for (int i = 1, sum = nums[0] % k; i < nums_size; ++i) {
      sum = (sum + nums[i]) % k;
      const auto iter = prefix_sum.find(sum);
      if (iter != prefix_sum.end() && iter->second < i) return true;
      prefix_sum.insert({sum, i + 1});
    }

    return false;
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  bool result = sln.checkSubarraySum({2, 4, 3}, 6);
  assert(result);
  result = sln.checkSubarraySum({1, 2, 3}, 5);
  assert(result);
  result = sln.checkSubarraySum({0, 1, 0, 3, 0, 4, 0, 4, 0}, 5);
  assert(!result);
  result = sln.checkSubarraySum({23, 0, 0}, 6);
  assert(result);

  auto start = std::chrono::system_clock::now();
  vector<int>test_vec;
  FILE *fp = fopen("testcase.txt", "rb");
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
  result = sln.checkSubarraySum(test_vec, test_k);
  std::cout << "time to calculate: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << " milliseconds" << std::endl;
  assert(!result);
  return 0;
}