
#include <string>

using std::string;

class Solution {
 public:
  string largestPalindromic(string num) {
    int digits_count[10] = {0};
    for (const char ch : num) ++digits_count[ch - '0'];
    // 1. use as many digits as possible
    // 2. put large digits on both side and small digits on middle. 9119 not 1991.
    int total_digits = 0;
    for (int i = 1; i < std::end(digits_count) - std::begin(digits_count); ++i) {
      if (digits_count[i] > 1) total_digits += (digits_count[i] / 2 * 2);
    }
    if (total_digits != 0) total_digits += digits_count[0] / 2 * 2;
    if (total_digits != num.size()) {
      ++total_digits;
      num.resize(total_digits);
      for (int i = std::end(digits_count) - std::begin(digits_count) - 1; 0 <= i; --i) {
        if (digits_count[i] & 1) {
          num[total_digits / 2] = i + '0';
          --digits_count[i];
          break;
        }
      }
    } else {
      num.resize(total_digits);
    }

    for (int i = std::end(digits_count) - std::begin(digits_count) - 1, num_index = 0, temp_total_digits = total_digits; 0 <= i; --i) {
      while (total_digits > 1 && digits_count[i] > 1) {
        num[num_index] = i + '0';
        num[temp_total_digits - num_index - 1] = i + '0';
        ++num_index;
        digits_count[i] -= 2;
        total_digits -= 2;
      }
    }
    return num;
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  string test_str = "444947137";
  sln.largestPalindromic(test_str);
  test_str = "00009";
  sln.largestPalindromic(test_str);
  return 0;
}
