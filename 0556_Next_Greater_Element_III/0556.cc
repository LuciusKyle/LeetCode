
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Solution {
 public:
  int nextGreaterElement(int n) {
    string num_str = std::to_string(n);
    std::next_permutation(num_str.begin(), num_str.end());
    long long result = atoll(num_str.c_str());
    return INT_MAX < result || result <= n ? -1 : result;
  }
};

int main(int argc, char *argv[]) {
  Solution sln;
  int rtn = sln.nextGreaterElement(12);
  assert(rtn == 21);
  rtn = sln.nextGreaterElement(4321);
  assert(rtn == -1);
  return 0;
  std::string str = argv[1];
  std::next_permutation(str.begin(), str.end());
  cout << str << endl;
  return 0;
}