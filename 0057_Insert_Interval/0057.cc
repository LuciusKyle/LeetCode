
#include <algorithm>
#include <vector>

using std::vector;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
 public:
  vector<Interval> insert(const vector<Interval> &intervals,
                          const Interval newInterval) {
    if (intervals.empty()) return {newInterval};
    vector<Interval> rtn;
    if (intervals.back().end < newInterval.start) {
      rtn.assign(intervals.cbegin(), intervals.cend());
      rtn.push_back(newInterval);
      return rtn;
    }
    int start_val = newInterval.start;
    int end_val = newInterval.end;
    bool started = false;
    bool finished = false;
    for (size_t i = 0; i < intervals.size(); ++i)
      if (started) {
        if (finished) {
          rtn.push_back(intervals[i]);
          continue;
        }
        if (intervals[i].start > end_val) {
          rtn.emplace_back(start_val, end_val);
          rtn.push_back(intervals[i]);
          finished = true;
        } else
          end_val = std::max(end_val, intervals[i].end);

      } else {
        if (end_val < intervals[i].start) {
          rtn.emplace_back(start_val, end_val);
          rtn.push_back(intervals[i]);
          started = true;
          finished = true;
          continue;
        }
        if (intervals[i].end < newInterval.start) {
          rtn.push_back(intervals[i]);
          continue;
        }
        started = true;
        start_val = std::min(intervals[i].start, newInterval.start);
        end_val = std::max(intervals[i].end, newInterval.end);
      }

    if (started && !finished) rtn.emplace_back(start_val, end_val);
    return rtn;
  }
};

int main(void) {
  const vector<Interval> intervals{{4, 7}, {10, 14}};
  Solution sln;
  auto rtn = sln.insert(intervals, {1, 2});
  rtn = sln.insert(intervals, {1, 4});
  rtn = sln.insert(intervals, {4, 5});
  rtn = sln.insert(intervals, {4, 7});
  rtn = sln.insert(intervals, {4, 8});
  rtn = sln.insert(intervals, {5, 6});
  rtn = sln.insert(intervals, {5, 8});
  rtn = sln.insert(intervals, {5, 10});
  rtn = sln.insert(intervals, {5, 11});
  rtn = sln.insert(intervals, {10, 11});
  rtn = sln.insert(intervals, {10, 15});
  rtn = sln.insert(intervals, {11, 15});
  rtn = sln.insert(intervals, {15, 16});

  return 0;
}
