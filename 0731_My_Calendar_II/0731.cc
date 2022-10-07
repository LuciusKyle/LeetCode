
#include <map>
#include <vector>

using std::map;
using std::vector;

class MyCalendarTwo {
 public:
  MyCalendarTwo() {}

  bool book(int start, int end) {
    bool triple_booking = false;
    vector<std::pair<int, int>> temp_overlaped;
    for (const auto &event : events_)
      if ((event.first <= start && start < event.second) || (start < event.first && event.first < end)) {
        const int overlaped_start = std::max(start, event.first);
        const int overlaped_end = std::min(end, event.second);
        for (const auto &p : overlaped_)
          if ((p.first <= overlaped_start && overlaped_start < p.second) || (overlaped_start < p.first && p.first < overlaped_end)) {
            triple_booking = true;
            break;
          }
        temp_overlaped.push_back({overlaped_start, overlaped_end});
      }
    if (!triple_booking) {
      for (const auto &p : temp_overlaped) overlaped_.push_back(p);
      events_.push_back({start, end});
    }
    return !triple_booking;
  }

 private:
  vector<std::pair<int, int>> events_;
  vector<std::pair<int, int>> overlaped_;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

int main(void) {
  MyCalendarTwo obj;
  vector<std::pair<int, int>> test_data{{36, 41}, {28, 34}, {40, 46}, {10, 18}, {4, 11}, {25, 34}, {36, 44}, {32, 40}, {34, 39}, {40, 49}};
  for (const auto p : test_data) {
    obj.book(p.first, p.second);
  }
  return 0;
}