
#include <map>
#include <set>
#include <vector>

using std::map;
using std::multimap;
using std::pair;
using std::vector;

class MyCalendarThree {
 public:
  MyCalendarThree() {}

  int book(int start, int end) {
    boundaries.insert({start, 1});
    boundaries.insert({end, 0});
    int curr_overlap = 0, ret_val = 0;
    for (const auto &p : boundaries) {
      if (p.second == 1)
        ++curr_overlap;
      else
        --curr_overlap;
      if (ret_val < curr_overlap) ret_val = curr_overlap;
    }
    return ret_val;
  }

 private:
  std::multiset<pair<int, int>> boundaries;  // first: boundaries, second: 1 for start, 0 for end;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */

int main(void) {
  MyCalendarThree obj;
  vector<pair<int, int>> test_data{{10, 20}, {50, 60}, {10, 40}, {5, 15}, {5, 10}, {25, 55}};
  test_data = {{1, 10}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
  for (const auto &p : test_data) {
    obj.book(p.first, p.second);
  }
  return 0;
}