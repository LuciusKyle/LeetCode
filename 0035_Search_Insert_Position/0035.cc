
#include <assert.h>
#include <vector>

using std::vector;

int searchInsert(int* nums, int numsSize, int target) {
  if (numsSize == 0 || target <= nums[0]) return 0;
  if (nums[numsSize - 1] < target) return numsSize;
  int lower_index = 0;
  int upper_index = numsSize - 1;
  while (upper_index - lower_index > 1) {
    const int mid_index = (lower_index + upper_index) / 2;
    if (target < nums[mid_index]) {
      upper_index = mid_index;
      continue;
    }
    if (nums[mid_index] < target) {
      lower_index = mid_index;
      continue;
    }
    return mid_index;
  }
  if (nums[lower_index] == target) return lower_index;
  if (target <= nums[upper_index]) return upper_index;
  return -1;
}

int main(void) {
  int arr[] = {1, 3, 5, 6};
  int rtn = searchInsert(arr, std::end(arr) - std::begin(arr), 4);
  assert(rtn == 2);
  rtn = searchInsert(arr, std::end(arr) - std::begin(arr), 4);
  assert(rtn == 2);
  rtn = searchInsert(arr, std::end(arr) - std::begin(arr), 0);
  assert(rtn == 0);
  rtn = searchInsert(arr, std::end(arr) - std::begin(arr), 7);
  assert(rtn == 4);

  return 0;
}
