
#include <algorithm>

class Solution {
 public:
  int maximumScore(int a, int b, int c) {
    int mid_num = std::max(std::min(b, c), std::min(a, std::max(b, c))), max_num = std::max(a, std::max(b, c)), min_num = std::min(a, std::min(b, c));
    int score = 0;
    const int max_mid_diff = max_num - mid_num;
    if (max_mid_diff < min_num) {
      min_num -= max_mid_diff;
      max_num -= max_mid_diff;
      score += max_mid_diff;

      score += (min_num / 2) * 3;
      const int removed = (min_num - min_num % 2);
      min_num -= removed;
      max_num -= removed;
      mid_num -= removed;

      score += mid_num;
      max_num -= mid_num;
      mid_num = 0;

      if (max_num != 0 && min_num != 0)
        ++score;
    } else {
      score += (min_num + mid_num); 
    }
    return score;
  }
};

int main(int argc,char*argv[]) {
  Solution sln;
  sln.maximumScore(6, 2, 1);
  return 0;
}