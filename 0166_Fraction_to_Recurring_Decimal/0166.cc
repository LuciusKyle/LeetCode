
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
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";
    bool minus = false;
    if ((numerator < 0 && 0 < denominator) || (0 < numerator && denominator < 0))
      minus = true;
    long long abs_numerator = std::abs((long long)numerator);
    long long abs_denominator = std::abs((long long)denominator);
    const int integer_part = abs_numerator / abs_denominator;
    if (integer_part * abs_denominator == abs_numerator) return std::to_string(minus ? -1 * integer_part : integer_part);
    abs_numerator -= integer_part * abs_denominator;
    map<long long, int> abs_numerator_map;
    vector<int> decimal_part;
    int decimal_count = 0;
    int cycle = -1;
    do {
      abs_numerator *= 10;
      if (0 < abs_numerator_map.count(abs_numerator)) {
        cycle = abs_numerator_map.at(abs_numerator);
        break;
      }
      decimal_part.push_back(abs_numerator / abs_denominator);
      abs_numerator_map[abs_numerator] = decimal_part.size();
      abs_numerator -= (decimal_part.back() * (long long)abs_denominator);
    } while (abs_numerator != 0);
    string result = minus ? "-" : "";
    result.append(std::to_string(integer_part));
    result.push_back('.');
    if (cycle == -1)
      for (const int digit : decimal_part)
        result.push_back(char(digit + '0'));
    else {
      for (int i = 0; i < decimal_part.size(); ++i) {
        if (i + 1 == cycle) result.push_back('(');
        result.push_back(char(decimal_part[i] + '0'));
      }
      result.push_back(')');
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution sln;
  sln.fractionToDecimal(-2147483648, 1);
  sln.fractionToDecimal(1, 90);
  sln.fractionToDecimal(4, 333);
  return 0;
}
