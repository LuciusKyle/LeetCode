
#include <limits.h>
#include <algorithm>
#include <map>
#include <vector>

using std::multimap;
using std::vector;

// 96 / 96 test cases passed. Status: Accepted. Runtime: 1168 ms.    5% beat.
class Solution00 {
public:
	int largestRectangleArea(const vector<int>& heights) {
		multimap<int, size_t> heights_index_map;
		for(size_t i =0;i<heights.size();++i)
			heights_index_map.insert({heights[i],i});
		
		return heights.empty() ? 0 : largestRectangleArea(heights, 0, heights.size() - 1);
	}

private:
	int largestRectangleArea(const vector<int>& heights, const size_t lower_index, const size_t upper_index) {
		if (upper_index - lower_index < 2)
			return std::max({ heights[lower_index], heights[upper_index], std::min(heights[lower_index], heights[upper_index]) * static_cast<int>(upper_index - lower_index + 1) });

		int min_val = INT_MAX;
		size_t min_val_index = 0;
		for (size_t i = lower_index; i <= upper_index; ++i)
			if (heights[i] < min_val) {
				min_val = heights[i];
				min_val_index = i;
			}
		return std::max({ min_val * static_cast<int>(upper_index - lower_index + 1), min_val_index == lower_index? 0 : largestRectangleArea(heights, lower_index, min_val_index - 1), min_val_index == upper_index? 0 : largestRectangleArea(heights, min_val_index + 1, upper_index) });
	}
		int largestRectangleArea(const vector<int>& heights, const size_t lower_index, const size_t upper_index) {
		if (upper_index - lower_index < 2)
			return std::max({ heights[lower_index], heights[upper_index], std::min(heights[lower_index], heights[upper_index]) * static_cast<int>(upper_index - lower_index + 1) });

		int min_val = INT_MAX;
		size_t min_val_index = 0;
		for (size_t i = lower_index; i <= upper_index; ++i)
			if (heights[i] < min_val) {
				min_val = heights[i];
				min_val_index = i;
			}
		return std::max({ min_val * static_cast<int>(upper_index - lower_index + 1), min_val_index == lower_index? 0 : largestRectangleArea(heights, lower_index, min_val_index - 1), min_val_index == upper_index? 0 : largestRectangleArea(heights, min_val_index + 1, upper_index) });
	}
};


class Solution {
public:
	int largestRectangleArea(const vector<int>& heights) {
		return heights.empty() ? 0 : largestRectangleArea(heights, 0, heights.size() - 1);
	}

private:
	int largestRectangleArea(const vector<int>& heights, const size_t lower_index, const size_t upper_index) {
		if (upper_index - lower_index < 2)
			return std::max({ heights[lower_index], heights[upper_index], std::min(heights[lower_index], heights[upper_index]) * static_cast<int>(upper_index - lower_index + 1) });

		int min_val = INT_MAX;
		size_t min_val_index = 0;
		for (size_t i = lower_index; i <= upper_index; ++i)
			if (heights[i] < min_val) {
				min_val = heights[i];
				min_val_index = i;
			}
		return std::max({ min_val * static_cast<int>(upper_index - lower_index + 1), min_val_index == lower_index? 0 : largestRectangleArea(heights, lower_index, min_val_index - 1), min_val_index == upper_index? 0 : largestRectangleArea(heights, min_val_index + 1, upper_index) });
	}

	int largestRectangleArea(const vector<int>& heights, const size_t lower_index, const size_t upper_index, const multimap<int, size_t> &heights_index_map, const int pre_min) {
		if (upper_index - lower_index < 2)
			return std::max({ heights[lower_index], heights[upper_index], std::min(heights[lower_index], heights[upper_index]) * static_cast<int>(upper_index - lower_index + 1) });

		auto map_iter = heights_index_map.cbegin();
		
		int min_val = map_iter->first;
		size_t min_val_index = map_iter->second;
		// for (size_t i = lower_index; i <= upper_index; ++i)
		// 	if (heights[i] < min_val) {
		// 		min_val = heights[i];
		// 		min_val_index = i;
		// 	}
		return std::max({ min_val * static_cast<int>(upper_index - lower_index + 1), min_val_index == lower_index? 0 : largestRectangleArea(heights, lower_index, min_val_index - 1), min_val_index == upper_index? 0 : largestRectangleArea(heights, min_val_index + 1, upper_index) });
	}
};

int main(int argc, char const* argv[]) {
	Solution sln;
	int rtn = sln.largestRectangleArea({ 2, 1, 5, 6, 2, 3 });
	rtn = sln.largestRectangleArea({ 0, 2, 0 });
	rtn = sln.largestRectangleArea({ 2, 1, 2 });
	return 0;
}
