
#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

constexpr int fillBits(const int s) {
  int bitmap = 0;
  for (int i = 0; i < s; ++i) {
    bitmap = bitmap << 1;
    bitmap |= 1;
  }
  return bitmap;
}

constexpr int kBitsMap[] = {fillBits(1), fillBits(2), fillBits(3), fillBits(4), fillBits(5), fillBits(6), fillBits(7), fillBits(8), fillBits(9), fillBits(10), fillBits(11), fillBits(12), fillBits(13), fillBits(14)};

class Solution {
 public:
  int maxScore(const vector<int>& nums) {
    int bitmap = (1 << nums.size()) - 1;
    answer_cache_.assign(bitmap + 1, -1);
    answer_cache_[0] = 0;
    return maxScore(nums, bitmap, 1);
  }

 private:
  vector<int> answer_cache_;

  int greatestCommonDivisor(int a, int b) const {
    // return __gcd(a, b);
    int temp;
    while (b) {
      temp = b;
      b = a % b;
      a = temp;
    }
    return a;
  }

  int maxScore(const vector<int>& nums, int bitmap, int depth) {
    if (answer_cache_[bitmap] != -1) return answer_cache_[bitmap];
    int max_score = 0;
    for (int i = 0; i + 1 < nums.size(); ++i)
      if (bitmap & (1 << i))
        for (int j = i + 1; j < nums.size(); ++j)
          if (bitmap & (1 << j))
            max_score = std::max(max_score, depth * greatestCommonDivisor(nums[i], nums[j]) + maxScore(nums, ~(1 << i) & ~(1 << j) & bitmap, depth + 1));
    answer_cache_[bitmap] = max_score;
    return max_score;
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  sln.maxScore({1, 2});
  return 0;
}
