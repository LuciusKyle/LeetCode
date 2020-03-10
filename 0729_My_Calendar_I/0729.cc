
#include <map>

using std::map;

class MyCalendar {
 public:
  MyCalendar() {
    events.insert({-1, -1});
    events.insert({1000000001, 1000000001});
  }

  bool book(int start, int end) {
    if (end <= start) return false;
    auto iter = events.lower_bound(start);
    // if (iter->first == start) return false;
    if (iter->first < end || start < (--iter)->second)
      return false;
    else
      return events.insert({start, end}).second;
  }

 private:
  map<int, int> events;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main(void) {
  MyCalendar mc;
  bool rtn = false;
  rtn = mc.book(10, 20);  // returns true
  rtn = mc.book(15, 25);  // returns false
  rtn = mc.book(20, 30);  // returns true
  return 0;
}
