
#include <map>
#include <vector>

using std::map;
using std::vector;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

// this is my solution.
// it's not good enough, although the time complexity is O(n * log n) which is
// the best time complexity that can be achieved, it's not efficient enough. the
// std::map is doing a sort, but it's not needed to sort Interval::end;
class Solution {
 public:
  vector<Interval> merge(const vector<Interval>& intervals) {
    map<int, int> end_points;
    for (const auto& one_interval : intervals) {
      if (end_points.find(one_interval.start) == end_points.end())
        end_points.insert({one_interval.start, 1});
      else
        ++end_points.at(one_interval.start);

      if (end_points.find(one_interval.end) == end_points.end())
        end_points.insert({one_interval.end, -1});
      else
        --end_points.at(one_interval.end);
    }
    int start = 0;
    int current_level = 0;
    bool ready_to_start = true;

    vector<Interval> rtn;
    for (auto map_iter = end_points.cbegin(); map_iter != end_points.cend();
         ++map_iter) {
      if (ready_to_start) {
        start = map_iter->first;
        ready_to_start = false;
      }
      current_level += map_iter->second;
      if (current_level == 0) {
        rtn.emplace_back(start, map_iter->first);
        ready_to_start = true;
      }
    }
    return rtn;
  }
};

int main(int argc, char const* argv[]) {
  Solution sln;

  return 0;
}
