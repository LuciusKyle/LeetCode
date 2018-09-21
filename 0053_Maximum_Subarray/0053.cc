
#include <assert.h>
#include <vector> // for std::begin() and std::end();

using std::vector;

int my_max_fun(int a, int b) { return a < b ? b : a; }

int maxSubArray(int* nums, int numsSize) {
  if (numsSize == 1) return nums[0];
  if (numsSize == 2)
    return my_max_fun((nums[0] + nums[1]), my_max_fun(nums[0], nums[1]));

  const int mid_index = (numsSize - 1) / 2;
  int left_max = nums[mid_index];
  int left_sum = left_max;
  int right_max = nums[mid_index + 1];
  int right_sum = right_max;
  for (int i = mid_index - 1; i >= 0; --i) {
    left_sum += nums[i];
    if (left_max < left_sum) left_max = left_sum;
  }
  for (int i = mid_index + 2; i < numsSize; ++i) {
    right_sum += nums[i];
    if (right_max < right_sum) right_max = right_sum;
  }
  return my_max_fun(right_max + left_max,
                    my_max_fun(maxSubArray(nums, mid_index + 1),
                               maxSubArray(nums + mid_index + 1,
                                           numsSize - (mid_index + 1))));
}

int main(void) {
  int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int rtn = maxSubArray(arr, std::end(arr) - std::begin(arr));
  assert(rtn == 6);
  return 0;
}
