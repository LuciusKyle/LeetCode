/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

constexpr int kPickedNumber = 6;
int guess(int num) {
  if (num < kPickedNumber)
    return 1;
  else if (kPickedNumber < num)
    return -1;
  else
    return 0;
}

class Solution {
 public:
  int guessNumber(int n) {
    int left_boundary = 1, right_boundary = n, result = guess(left_boundary + (right_boundary - left_boundary) / 2);
    n = left_boundary + (right_boundary - left_boundary) / 2;
    while (result && right_boundary - left_boundary != 1) {
      n = left_boundary + (right_boundary - left_boundary) / 2;
      if (result < 0)
        right_boundary = n;
      else
        left_boundary = n;
      result = guess(left_boundary + (right_boundary - left_boundary) / 2);
    }
    n = left_boundary + (right_boundary - left_boundary) / 2;
    if (right_boundary - left_boundary == 1)
      return guess(left_boundary) == 0 ? left_boundary : right_boundary;
    else
      return n;
  }
};

int main(void) {
  Solution sln;
  int ret = sln.guessNumber(10);
  return 0;
}