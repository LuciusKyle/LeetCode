
#include <vector>

using std::vector;

class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int new_planted = 0;
    for (int i = 0, pre_planted = false; i < flowerbed.size(); ++i) {
      if (pre_planted && flowerbed[i] == 1) {
        --new_planted;
      }
      if (flowerbed[i] == 0 && pre_planted == false) {
        ++new_planted;
        flowerbed[i] = 1;
      }
      pre_planted = (flowerbed[i] == 1);
    }
    return n <= new_planted;
  }
};