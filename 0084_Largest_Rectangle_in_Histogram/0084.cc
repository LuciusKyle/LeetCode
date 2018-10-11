#include <iostream>

#include <limits.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using std::multimap;
using std::set;
using std::vector;

class Solution {
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

int main(int argc, char const* argv[]) {
	std::cout << __cplusplus << std::endl;

	Solution sln;
	int rtn = sln.largestRectangleArea({ 2, 1, 5, 6, 2, 3 });
	rtn = sln.largestRectangleArea({ 0, 2, 0 });
	rtn = sln.largestRectangleArea({ 2, 1, 2 });
	return 0;
}
