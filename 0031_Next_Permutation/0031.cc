
#include <climits>
#include <vector>  // only for std::begin() and std::end(); this is not a C++ solution.

using std::vector;

void nextPermutation(int* nums, int numsSize) {
  int revers_position = 0;
  for (int i = numsSize - 1; i > 0 /*don't let i = 0*/; --i) {
    if (nums[i - 1] < nums[i]) {
      revers_position = i;
      for (int ii = numsSize - 1; ii > i - 1; --ii) {
        if (nums[ii] > nums[i - 1]) {
          nums[ii] ^= nums[i - 1];
          nums[i - 1] ^= nums[ii];
          nums[ii] ^= nums[i - 1];
          break;
        }
      }
      break;
    }
  }
  for (int i = 0; i < (numsSize - revers_position) / 2; ++i) {
    nums[i + revers_position] ^= nums[numsSize - 1 - i];
    nums[numsSize - 1 - i] ^= nums[i + revers_position];
    nums[i + revers_position] ^= nums[numsSize - 1 - i];
  }
}

int main(void) {
  int a[] = {5, 4, 7, 5, 3, 2};
  nextPermutation(a, std::end(a) - std::begin(a));
  return 0;
}

// the above is my solution.
//////////////////////////////////////////////////////////////////
// the following is LeetCode 100% beat solution.

void swap_ints(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int get_rightmost_least_upper_bound_idx(int* numbers, int n_vals, int idx) {
  int i;
  int rmlub = idx;
  int current_min = INT_MAX;
  for (i = idx; i < n_vals; i++) {
    if (numbers[i] > numbers[idx]) {
      if (numbers[i] <= current_min) {
        current_min = numbers[i];
        if (i > rmlub) {
          rmlub = i;
        }
      }
    }
  }
  return rmlub;
}

int get_longest_nonincreasing_suffix_idx(int* numbers, int n) {
  int suffix_base_idx;
  int i;
  for (i = n - 1; i > 1; i--) {
    suffix_base_idx = i;
    if (numbers[i] <= numbers[i - 1]) {
      suffix_base_idx -= 1;
    } else {
      suffix_base_idx = i;
      break;
    }
  }
  return suffix_base_idx;
}

void reverse_slice(int* numbers, int lo, int hi) {
  int n_swaps = (hi - lo) / 2;
  int i;
  for (i = 0; i < n_swaps; i++) {
    swap_ints(&numbers[lo], &numbers[hi - 1]);
    lo++;
    hi--;
  }
}

void next_permutation_int(int* numbers, int n_vals) {
  if (n_vals == 1) {
    return;
  } else if (n_vals == 2) {
    reverse_slice(numbers, 0, 2);
  } else {
    int pivot = get_longest_nonincreasing_suffix_idx(numbers, n_vals) - 1;
    int rightmost_successor;
    rightmost_successor =
        get_rightmost_least_upper_bound_idx(numbers, n_vals, pivot);
    if (rightmost_successor == 0) {
      reverse_slice(numbers, 0, n_vals);
    } else {
      swap_ints(&numbers[pivot], &numbers[rightmost_successor]);
      reverse_slice(numbers, pivot + 1, n_vals);
    }
  }
}

void nextPermutation_LeetCode100beat(int* nums, int numsSize) {
  next_permutation_int(nums, numsSize);
}