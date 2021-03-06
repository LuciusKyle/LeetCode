

#include <assert.h>
#include <algorithm>  // for std::min().
#include <vector>

int maxArea(int* height, int heightSize) {
  int left = 0;
  int right = heightSize - 1;
  int max_area = 0;
  while (right > left) {
    const int current_area = (right - left) * (height[left] < height[right] ? height[left] : height[right]);
    if (max_area < current_area) max_area = current_area;
    if (height[left] < height[right])
      ++left;
    else if (height[left] > height[right])
      --right;
    else {
      ++left;
      --right;
    }
  }
  return max_area;
}

using std::vector;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int left = 0;
    int right = static_cast<int>(height.size()) - 1;
    int max_area = 0;
    while (right > left) {
      const int current_area = (right - left) * (height[left] < height[right] ? height[left] : height[right]);
      if (max_area < current_area) max_area = current_area;
      if (height[left] < height[right]) {
        ++left;
        continue;
      }
      if (height[left] > height[right]) {
        --right;
        continue;
      }
      ++left;
      --right;
    }
    return max_area;
  }
};

int main(void) {
  int height_array[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  int rtn = maxArea(height_array, sizeof(height_array) / sizeof(int));
  assert(rtn == 49);
  return 0;
}
