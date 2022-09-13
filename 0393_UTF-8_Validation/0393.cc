
#include <limits.h>

#include <vector>

using std::vector;

//     Number of Bytes   |        UTF-8 Octet Sequence
//                       |              (binary)
//   --------------------+-----------------------------------------
//            1          |   0xxxxxxx
//            2          |   110xxxxx 10xxxxxx
//            3          |   1110xxxx 10xxxxxx 10xxxxxx
//            4          |   11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

constexpr int kEighthBit = 1 << 7, kSeventhBit = 1 << 6;
constexpr int k2BytesFlag = 0xc0, k3BytesFlag = 0xe0, k4BytesFlag = 0xf0;

class Solution {
 public:
  bool validUtf8(vector<int>& data) {
    const int length = data.size();
    for (int i = 0; i < length; ++i)
      if ((kEighthBit & data[i]) != 0) {
        if ((k4BytesFlag & data[i]) == k4BytesFlag && ((1 << 3) & data[i]) == 0) {
          if (i + 3 < length && (data[i + 1] & kEighthBit) == kEighthBit && (data[i + 1] & kSeventhBit) == 0 && (data[i + 2] & kEighthBit) == kEighthBit && (data[i + 2] & kSeventhBit) == 0 && (data[i + 3] & kEighthBit) == kEighthBit && (data[i + 3] & kSeventhBit) == 0) {
            i += 3;
          } else
            return false;
        } else if ((k3BytesFlag & data[i]) == k3BytesFlag && ((1 << 4) & data[i]) == 0) {
          if (i + 2 < length && (data[i + 1] & kEighthBit) == kEighthBit && (data[i + 1] & kSeventhBit) == 0 && (data[i + 2] & kEighthBit) == kEighthBit && (data[i + 2] & kSeventhBit) == 0) {
            i+=2;
          } else
            return false;
        } else if ((k2BytesFlag & data[i]) == k2BytesFlag && ((1 << 5) & data[i]) == 0) {
          if (i + 1 < length && (data[i + 1] & kEighthBit) == kEighthBit && (data[i + 1] & kSeventhBit) == 0)
            ++i;
          else
            return false;
        } else
          return false;
      }
    return true;
  }
};

int main(void) {
  vector<int> test_vec = {235, 140, 4};
  Solution sln;
  sln.validUtf8(test_vec);
  test_vec = {197, 130, 1};
  sln.validUtf8(test_vec);
  return 0;
}