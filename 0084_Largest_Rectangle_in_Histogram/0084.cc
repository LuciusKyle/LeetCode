#include <assert.h>
#include <limits.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <stack>
#include <vector>

using std::multimap;
using std::set;
using std::vector;

// 18% beat.
class Solution_old {
public:
	int largestRectangleArea(const vector<int>& heights) {
		multimap<int, size_t> heights_index_map;
		for (size_t i = 0; i < heights.size(); ++i) heights_index_map.insert({ heights[i], i });
		set<size_t> indexes;
		int rtn = 0;
		for (auto map_iter = heights_index_map.cbegin(); map_iter != heights_index_map.cend(); ++map_iter) {
			auto set_iter = indexes.insert(map_iter->second).first;
			auto lower_iter = set_iter;
			const size_t lower_index = lower_iter != indexes.begin() ? (*(--lower_iter)) + 1 : 0;
			const int area = map_iter->first * (static_cast<int>(++set_iter == indexes.end() ? heights.size() : *(set_iter)) - static_cast<int>(lower_index));
			if (rtn < area) rtn = area;
		}
		return rtn;
	}
};

// not finished.
class Solution {
 public:
  int largestRectangleArea(const vector<int>& heights) {
    std::stack<size_t> stk;
    int max_area = 0;
    for (size_t i = 0; i < heights.size(); ++i) {
      if (stk.empty() || heights[stk.top()] < heights[i]) {
        stk.push(i);
      } else {
        while (!stk.empty() && heights[i] <= heights[stk.top()]) {
          const int cur_area = heights[stk.top()] * int(i - stk.top());
          if (max_area < cur_area) max_area = cur_area;
          stk.pop();
        }
        stk.push(i);
      }
    }
    while (!stk.empty()) {
      const int cur_area = heights[stk.top()] * int(heights.size() - stk.top());
      if (max_area < cur_area) max_area = cur_area;
			stk.pop();
    }
    return max_area;
  }
};

int main(int argc, char const* argv[]) {
  std::cout << __cplusplus << std::endl;

  Solution sln;
  int rtn = sln.largestRectangleArea({2, 1, 5, 6, 2, 3});
  rtn = sln.largestRectangleArea({0, 2, 0});
  rtn = sln.largestRectangleArea({2, 1, 2});

  Solution_old old_sln;
  std::random_device rd;
  std::uniform_int_distribution<int> dist(0, 0x1000);
  for (size_t test_count = 0; test_count < 10000; ++test_count) {
    vector test_sample(dist(rd), 0);
    for (size_t i = 0; i < test_sample.size(); ++i) test_sample[i] = dist(rd);
		int result = old_sln.largestRectangleArea(test_sample);
    int result1 = sln.largestRectangleArea(test_sample);
		assert(old_sln.largestRectangleArea(test_sample) == sln.largestRectangleArea(test_sample));
    std::cout << test_count << std::endl;
  }

  return 0;
}
