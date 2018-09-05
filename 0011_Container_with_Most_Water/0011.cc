

#include <assert.h>
#include <algorithm>  // for std::min().

int maxArea(int* height, int heightSize) {
  int left = 0;
  int right = heightSize - 1;
  int max_area = 0;
  while (right > left) {
    const int current_area =
        (right - left) * std::min(height[left], height[right]);
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

int main(void) {
  int height_array[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  int rtn = maxArea(height_array, sizeof(height_array) / sizeof(int));
  assert(rtn == 49);
  return 0;
}
