
#include <vector>
#include<limits.h>

using std::vector;

int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size();
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        
        double num = (nums[mid] < nums[0]) == (target < nums[0])
                   ? nums[mid]
                   : target < nums[0] ? -INFINITY : INFINITY;
                   
        if (num < target)
            lo = mid + 1;
        else if (num > target)
            hi = mid;
        else
            return mid;
    }
    return -1;
}

int binary_search(const int* nums, const int numsSize, const int target) {
  if (numsSize < 4) {
    for (int i = 0; i < numsSize; ++i)
      if (nums[i] == target) return i;
    return -1;
  }
  const int mid_index = numsSize / 2;
  const int mid_val = nums[mid_index];
  if (target < mid_val)
    return binary_search(nums, mid_index, target);
  else if (mid_val < target)
    return binary_search(nums + mid_index, numsSize - mid_index, target);
  else
    return mid_index;
}

// wrong answer, this fuction did find the number, but will not return the correct array index.
int search_wrong(int* nums, int numsSize, int target) {
  if (numsSize < 4) {
    for (int i = 0; i < numsSize; ++i)
      if (nums[i] == target) return i;
    return -1;
  }
  
  const int mid_index = numsSize / 2;
  const int mid_val = nums[mid_index - 1];
  if (nums[0] < mid_val)  // left half is ordered.
  {
    if (nums[0] <= target && target <= mid_val) {
      // target is in left half.
      return search(nums, mid_index, target);
    }
    else{
      // target is in right half.
      return search(nums + mid_index, numsSize - mid_index, target);
    }
  } else if (mid_val < nums[numsSize - 1])  // right half is ordered.
  {
    if (mid_val <= target && target <= nums[numsSize - 1]) {
      // target is in left half.
      return search(nums + mid_index, numsSize - mid_index, target);
    } else {
      // target is in right half.
      return search(nums, mid_index, target);
    }
  }
}

int search(int* nums, int numsSize, int target){
  int lower_index = 0;
  int upper_index = numsSize -1;

  int target_index = -1;
  while(upper_index - lower_index > 1){
    if(upper_index - lower_index < 3){
      for(int i = lower_index; i < upper_index; ++i){
        if(nums[i]==target)
        target_index = i;
      }
    }
    const int mid_index = (upper_index + lower_index) / 2;
    if(nums[mid_index] <= nums[lower_index]) // left half is ordered.
    {
      if()
    }
    else if (nums[0] <= )
  }
  return target_index;
}

int main(void){
  int arr[] = {4,5,6,7,0,1,2};
  int rtn = search(arr, std::end(arr) - std::begin(arr), 2);
  return 0;
}