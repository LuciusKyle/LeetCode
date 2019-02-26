
// https://leetcode.com/problems/sum-of-two-integers/discuss/84305/Share-my-C%2B%2B-solutionseasy-to-understand

class Solution {
 public:
  int getSum(int a, int b) {
    int sum = a;

    while (b != 0) {
      sum = a ^ b;       // calculate sum of a and b without thinking the carry
      b = (a & b) << 1;  // calculate the carry
      a = sum;           // add sum(without carry) and carry
    }

    return sum;
  }
};