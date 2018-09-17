
#include<vector>

using std::vector;

// this is not the best solution.
// my time complexity is O(n) and space complexity is O(1), both are same as the question's lower bound.
// the point is that this question doesn't require a stable removement, in other word, the order of element can be changed.
int removeElement(int* nums, int numsSize, int val) {
  size_t identical = 0;
  for (size_t i = 0; i < numsSize; ++i) {
    if (nums[i] == val) {
      ++identical;
      continue;
    }
    if (identical != 0) {
      nums[i] ^= nums[i - identical];
      nums[i - identical] ^= nums[i];
      nums[i] ^= nums[i - identical];
    }
  }
  return numsSize - identical;
}

int main(void)
{
  int a[] = {0,1,2,2,3,0,4,2};
  removeElement(a, 8, 2);
  return 0;
}