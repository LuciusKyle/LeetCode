
#include <assert.h>
#include <vector>

using std::vector;

// C++ version.
class Solution {
public:
	int maxProfit(const vector<int>& prices) {
		int min_price = INT_MAX;
		int max_profit = 0;
		for (int i = 0; i < prices.size(); ++i) {
			if (prices[i] < min_price) min_price = prices[i];
			if (max_profit < prices[i] - min_price)
				max_profit = prices[i] - min_price;
		}
        return max_profit;
	}
};

// C language version.
int maxProfit(int* prices, int pricesSize) {
	int min_price = INT_MAX;
	int max_profit = 0;
	for (int i = 0; i < pricesSize; ++i) {
		if (prices[i] < min_price) min_price = prices[i];
		if (max_profit < prices[i] - min_price)
			max_profit = prices[i] - min_price;
	}
	return max_profit;
}

int main(void) {
	Solution sln;
	assert(5 == sln.maxProfit({ 7, 1, 5, 3, 6, 4 }));
	assert(1 == sln.maxProfit({ 1, 2 }));
	assert(0 == sln.maxProfit({ 1, 1 }));
	assert(0 == sln.maxProfit({ 1 }));
	assert(0 == sln.maxProfit(vector<int>()));
	return 0;
}
