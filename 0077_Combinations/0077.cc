
// 0077 and 0078 share a same solution.

#include<vector>
#include<unordered_set>

using std::vector;
using std::unordered_set;

class Solution {
public:
	vector<vector<int>> subsets(const vector<int>& nums) {
		vector<vector<int>> rtn;
		for (size_t i = 0; i <= nums.size(); ++i) {
			vector<int> buffer;
			combine(rtn, buffer, nums, 0, i);
		}
		return rtn;
	}
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> rtn;
		vector<int> nums_set;
		for (int i = 0; i < n; ++i)
			nums_set.push_back(i + 1);

		vector<int> buffer;
		combine(rtn, buffer, nums_set, 0, k);
		return rtn;
	}
private:
	void combine(vector<vector<int>> &rtn, vector<int>& buffer, const vector<int> &set, const size_t start_index, const size_t k) {
		if (k == 0) {
			rtn.push_back(buffer);
			return;
		}
		if (set.size() - start_index < k)
			return;

		for (size_t i = start_index; i < set.size(); ++i) {
			buffer.push_back(set[i]);
			combine(rtn, buffer, set, i + 1, k - 1);
			buffer.pop_back();
		}
	}
};

int main(void) {
	Solution sln;
	auto rtn = sln.combine(4, 3);
	rtn = sln.subsets({ 1,2,3 });
	return 0;
}

