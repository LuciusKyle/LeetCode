
#include <math.h>
#include <array>
#include <string>
#include <vector>

using std::array;
using std::string;
using std::vector;

// constexpr array<char, 4> DigitOne{'?', '?', '?', '?'};
// constexpr array<char, 4> DigitTwo{'a', 'b', 'c', '?'};
// constexpr array<char, 4> DigitThree{'d', 'e', 'f', '?'};
// constexpr array<char, 4> DigitFour{'g', 'h', 'i', '?'};
// constexpr array<char, 4> DigitFive{'j', 'k', 'l', '?'};
// constexpr array<char, 4> DigitSix{'m', 'n', 'o', '?'};
// constexpr array<char, 4> DigitSeven{'p', 'q', 'r', 's'};
// constexpr array<char, 4> DigitEight{'t', 'u', 'v', '?'};
// constexpr array<char, 4> DigitNine{'w', 'x', 'y', 'z'};
// constexpr array<array<char, 4>, 9> Digit_to_Lettter_map{
//     DigitOne, DigitTwo,   DigitThree, DigitFour, DigitFive,
//     DigitSix, DigitSeven, DigitEight, DigitNine};

const vector<string> Digit_to_Lettter_map{"",    "abc",  "def", "ghi", "jkl",
                                          "mno", "pqrs", "tuv", "wxyz"};

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> rtn;
    rtn.reserve(static_cast<size_t>(pow(4, digits.size())));
    string str;
    func_name(rtn, digits, str);
    return rtn;
  }

 private:
  void func_name(
      vector<string> &rtn_vec, const string digits,
      string &str_letters)  // I don't come up with a good function name.
  {
    if (digits.empty()) {
      if (!str_letters.empty()) rtn_vec.push_back(str_letters);
      return;
    }
    const int num = digits.front() + (1 - '1') - 1;
    for (const auto ch : Digit_to_Lettter_map[num]) {
      str_letters.push_back(ch);
      func_name(rtn_vec, string(digits.begin() + 1, digits.end()), str_letters);
      str_letters.pop_back();
    }
    return;
  }
};

int main(void) {
  Solution sln;
  auto rtn = sln.letterCombinations("234");
  return 0;
}