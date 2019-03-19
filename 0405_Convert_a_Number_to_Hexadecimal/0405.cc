
#include <assert.h>
#include <iostream>
#include <string>
#include <string_view>  // not used.
#include <vector>

using std::string;

constexpr char Hex[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

constexpr int hex_mask[] = {0xf << (32 - 4),     0xf << (32 - 4 * 2),
                            0xf << (32 - 4 * 3), 0xf << (32 - 4 * 4),
                            0xf << (32 - 4 * 5), 0xf << (32 - 4 * 6),
                            0xf << (32 - 4 * 7), 0xf << (32 - 4 * 8)};

class Solution {
 public:
  string toHex(int num) {
    string rtn;
    for (size_t i = 0; i < std::end(hex_mask) - std::begin(hex_mask); ++i) {
      auto val = unsigned(hex_mask[i] & num) >> (32 - 4 * (i + 1));
      if (val != 0 || !rtn.empty()) rtn.push_back(Hex[val]);
    }
    return rtn.empty() ? "0" : rtn;
  }
};

int main(void) {
  Solution sln;
  char hexadecimal[24] = {'\0'};
  for (int i = -12; i < 999; ++i) {
    sprintf(hexadecimal, "%x", i);
    if(hexadecimal != sln.toHex(i)){
      std::cout << "my answer: " << sln.toHex(i) << "\t"
                << "real answer: " << hexadecimal << std::endl;
    }
  }

  return 0;
}
