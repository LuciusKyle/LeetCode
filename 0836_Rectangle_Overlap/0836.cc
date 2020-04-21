
#include <vector>

using std::vector;

class Solution {
 public:
  bool isRectangleOverlap(const vector<int>& rec1, const vector<int>& rec2) {
    const vector<int>& left_rec = rec1[0] < rec2[0] ? rec1 : rec2;
    const vector<int>& right_rec = rec1[0] < rec2[0] ? rec2 : rec1;
    if (left_rec[2] <= right_rec[0]) return false;
    const vector<int>& upper_rec = rec1[1] < rec2[1] ? rec2 : rec1;
    const vector<int>& lower_rec = rec1[1] < rec2[1] ? rec1 : rec2;
    return upper_rec[1] < lower_rec[3];
  }
};

int main(void) {
  Solution sln;
  sln.isRectangleOverlap({0, 0, 2, 2}, {1, 1, 3, 3});
  sln.isRectangleOverlap({5, 15, 8, 18}, {0, 3, 7, 9});
  return 0;
}
