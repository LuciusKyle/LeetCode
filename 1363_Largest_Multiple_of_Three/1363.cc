
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  string largestMultipleOfThree(const vector<int>& digits) {
    int digit_count[10]{0};
    int sum = 0;
    for (const int digit : digits) {
      sum += digit;
      ++digit_count[digit];
    }
    const int diff = sum % 3;
    if (diff == 0) {
      // do nothing!
    }
    if (diff == 1) {
      if (digit_count[1] != 0) {
        --digit_count[1];
      } else if (digit_count[4] != 0) {
        --digit_count[4];
      } else if (digit_count[7] != 0) {
        --digit_count[7];
      } else if (1 < digit_count[2]) {
        digit_count[2] -= 2;
      } else if (digit_count[2] != 0 && digit_count[5] != 0) {
        --digit_count[2];
        --digit_count[5];
      } else if (1 < digit_count[5]) {
        digit_count[5] -= 2;
      } else if (digit_count[2] != 0 && digit_count[8] != 0) {
        --digit_count[2];
        --digit_count[8];
      } else if (digit_count[5] != 0 && digit_count[8] != 0) {
        --digit_count[5];
        --digit_count[8];
      } else if (1 < digit_count[8]) {
        digit_count[8] -= 2;
      }
    }
    if (diff == 2) {
      if (digit_count[2] != 0) {
        --digit_count[2];
      } else if (digit_count[5] != 0) {
        --digit_count[5];
      } else if (digit_count[8] != 0) {
        --digit_count[8];
      } else if (1 < digit_count[1]) {
        digit_count[1] -= 2;
      } else if (digit_count[1] != 0 && digit_count[4] != 0) {
        --digit_count[1];
        --digit_count[4];
      } else if (1 < digit_count[4]) {
        digit_count[4] -= 2;
      } else if (digit_count[1] != 0 && digit_count[7] != 0) {
        --digit_count[1];
        --digit_count[7];
      } else if (digit_count[4] != 0 && digit_count[7] != 0) {
        --digit_count[4];
        --digit_count[7];
      } else if (1 < digit_count[7]) {
        digit_count[7] -= 2;
      }
    }
    const char dict[] = "0123456789";
    bool all_zero = digit_count[0] != 0;
    for (int i = 1; i < 10; ++i) {
      if (digit_count[i] != 0) all_zero = false;
    }
    if (all_zero) return "0";
    string result;
    result.reserve(digits.size());
    for (int i = 9; 0 <= i; --i) {
      for (int j = 0; j < digit_count[i]; ++j)
        result.push_back(dict[i]);
    }
    return result;
  }
};