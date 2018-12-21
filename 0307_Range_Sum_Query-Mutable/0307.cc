
#include <assert.h>
#include <algorithm>
#include <vector>
#if defined __cplusplus && 201703L <= __cplusplus
#include <execution> // this is the new header from C++17.
#endif

using std::vector;

class NumArray {
public:
	NumArray(const vector<int> nums) :sums_cache_(nums), nums_(nums){
		for (size_t i = 1; i < nums.size(); ++i)
			sums_cache_[i] += sums_cache_[i - 1];
	}

	void update(int i, int val) {
		const int var = val - nums_[i];
		nums_[i] = val;
#if defined __cplusplus && 201703L <= __cplusplus
		std::transform(std::execution::par_unseq, sums_cache_.cbegin() + i, sums_cache_.cend(), sums_cache_.begin() + i, [var](const int sum)->int {return sum + var; });
#else
		std::transform(sums_cache_.cbegin() + i, sums_cache_.cend(), sums_cache_.begin() + i, [var](const int sum)->int {return sum + var; });
#endif
	}

	int sumRange(const int begin, const int end) {
		if (begin) return sums_cache_[end] - sums_cache_[begin - 1];
		else return sums_cache_[end];
	}

private:
	vector<int> sums_cache_;
	vector<int> nums_;
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */


int main(void) {
	//NumArray obj({ 0, 1, 2, 3 });
	//assert(3 == obj.sumRange(0, 2));
	//assert(6 == obj.sumRange(0, 3));
	//assert(1 == obj.sumRange(1, 1));

	//NumArray obj({ 0, 1, 2, 3, 4, 5 });
	//assert(3 == obj.sumRange(0, 2));
	//assert(14 == obj.sumRange(2, 5));
	//assert(15 == obj.sumRange(0, 5));

	//NumArray obj({ -8261, 2300, -1429, 6274, 9650, -3267, 1414, -8102, 6251, -5979, -5291, -4616, -4703 });
	//obj.sumRange(12, 12);
	//for (int i = 0; i <= 12; ++i)
	//	for (int j = i; j <= 12; ++j) obj.sumRange(i, j);

	//NumArray obj({ 0, 1, 2, 3, 4 });
	//assert(3 == obj.sumRange(4, 4));

	NumArray obj({ 1 });
	assert(1 == obj.sumRange(0, 0));

	return 0;
}
