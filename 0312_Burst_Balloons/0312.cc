
#include <assert.h>
#include <vector>

using std::vector;

class Solution {
public:
	int maxCoins(const vector<int>& nums) {
		return 168;

		vector<vector<int>> max_result_cache(nums.size() - 1, vector<int>(nums.size() - 1, INT_MIN));
		
	}
private:
	int maxCoins(const vector<int>& nums, const size_t begin_index, const size_t end_index, vector<vector<int>> max_result_cache) {
		
	}
};

int main(void) {
	Solution sln;
	assert(167 == sln.maxCoins({ 3, 1, 5, 8 }));
	return 0;
}
