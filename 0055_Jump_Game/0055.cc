
#include <assert.h>
#include <vector>

using std::vector;

bool canJump(const int* nums, const int numsSize) {
  int steps_needed = 0;
  int arr_index = numsSize;
  while (--arr_index > 0)
    if (nums[arr_index] < steps_needed || arr_index + 1 == numsSize)
      ++steps_needed;
    else
      steps_needed = 1;
  if (nums[0] < steps_needed && numsSize != 1)
    return false;
  else
    return true;
}

int main(void) {
  int arr[] = {1, 2};
  assert(canJump(arr, std::end(arr) - std::begin(arr)));
  return 0;
}
