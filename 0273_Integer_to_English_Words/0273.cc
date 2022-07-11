
#include <assert.h>

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

const string nums_to_Eng_within_20[]{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"};
const string Tens[]{"invalid", "invalid", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety", "Hundred"};

class Solution {
 public:
  string numberToWords(int num) {
    string result;

    // Billion
    if (num / 1'000'000'000) result.append(numberToWordsWithin1000(num / 1'000'000'000) + "Billion ");

    // Million
    num %= 1'000'000'000;
    if (num / 1'000'000) result.append(numberToWordsWithin1000(num / 1'000'000) + "Million ");

    // Thousand
    num %= 1'000'000;
    if (num / 1'000) result.append(numberToWordsWithin1000(num / 1'000) + "Thousand ");

    //
    result.append(numberToWordsWithin1000(num % 1000));
    if (result.empty()) result = "Zero";
    if (result.back() == ' ') result.pop_back();
    return result;
  }

 private:
  string numberToWordsWithin1000(int num) {
    assert(num < 1000);
    string result;
    // Hundred
    if (99 < num) {
      result.append(nums_to_Eng_within_20[num / 100] + " Hundred ");
    }
    num %= 100;
    if (0 == num) return result;
    if (num < 21)
      result.append(nums_to_Eng_within_20[num] + " ");
    else {
      result.append(Tens[num / 10] + " ");
      if (num % 10 != 0)
        result.append(nums_to_Eng_within_20[num % 10] + " ");
    }
    return result;
  }
};

int main(void) {
  Solution sln;
  for (int i = 1; i < 222; ++i) {
    cout << sln.numberToWords(i) << "\n";
  }
  cout << endl;
  return 0;
}
