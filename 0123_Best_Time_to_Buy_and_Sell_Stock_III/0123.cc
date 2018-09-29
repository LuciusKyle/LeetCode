#include<limits.h>
#include<assert.h>
#include<array>

int maxProfit_Transaction(const int* prices, const int pricesSize) {
	int min_price = INT_MAX;
	int max_profit = 0;
	for (int i = 0; i < pricesSize; ++i) {
		if (prices[i] < min_price) min_price = prices[i];
		if (max_profit < prices[i] - min_price)
			max_profit = prices[i] - min_price;
	}
	return max_profit;
}

int maxProfit(const int* prices, const int pricesSize) {
	int max_profit = 0;
	for (int i = 0; i <= pricesSize; ++i) {
		int profit = maxProfit_Transaction(prices + i, pricesSize - i) + maxProfit_Transaction(prices, i);
		if (max_profit < profit)
			max_profit = profit;
	}
	return max_profit;
}

int main(void) {
	const int arr0[] = { 3,3,5,0,0,3,1,4 };
	assert(6 == maxProfit(arr0, std::end(arr0) - std::begin(arr0)));

	const int arr1[] = { 7,6,4,3,1 };
	assert(0 == maxProfit(arr1, std::end(arr1) - std::begin(arr1)));

	const int arr2[] = { 1,2 };
	assert(1 == maxProfit(arr2, std::end(arr2) - std::begin(arr2)));

	const int arr3[] = { 1 };
	assert(0 == maxProfit(arr3, std::end(arr3) - std::begin(arr3)));
	
	assert(0 == maxProfit(nullptr, 0));
	return 0;
}