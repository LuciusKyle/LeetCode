
#include <math.h>

#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

// wrong when numerator = 1 and denominator = 90;
class Solution {
 public:
  string fractionToDecimal(int numerator, const int denominator) {
    const int integer_part = numerator / denominator;
    if (integer_part * denominator == numerator) return std::to_string(integer_part);
    numerator -= integer_part * denominator;
    map<int, int> numerator_map;
    vector<int> decimal_part;
    int decimal_count = 0;
    int cycle = -1;
    while (true) {
      numerator *= 10;
      if (0 < numerator_map.count(numerator)) {
        cycle = numerator_map.at(numerator);
        break;
      }
      numerator_map.insert({numerator, decimal_count});  // or possible {numerator,decimal_part.size()};
      if (numerator < denominator) {
        decimal_part.push_back(0);
        continue;
      }
      decimal_part.push_back(numerator / denominator);
      if (numerator % denominator == 0) break;
      numerator %= denominator;
      ++decimal_count;
    }
    string result = std::to_string(integer_part);
    result.push_back('.');
    if (cycle == -1) {
      for (const int digit : decimal_part)
        result.push_back(char(digit + '0'));
    } else {
      for (int i = 0; i < decimal_part.size(); ++i) {
        if (i == cycle) result.push_back('(');
        result.push_back(char(decimal_part[i] + '0'));
      }
      result.push_back(')');
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution sln;
  sln.fractionToDecimal(4, 333);
  return 0;
}