
#include<vector>
#include<algorithm>

using std::vector;

class Solution {
private:
	int getkth(int s[], int m, int l[], int n, int k) {
		// let m <= n
		if (m > n)
			return getkth(l, n, s, m, k);
		if (m == 0)
			return l[k - 1];
		if (k == 1)
			return std::min(s[0], l[0]);

		int i = std::min(m, k / 2), j = std::min(n, k / 2);
		if (s[i - 1] > l[j - 1])
			return getkth(s, m, l + j, n - j, k - j);
		else
			return getkth(s + i, m - i, l, n, k - i);
		return 0;
	}

	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int l = (m + n + 1) >> 1;
		int r = (m + n + 2) >> 1;
		return (getkth(A, m, B, n, l) + getkth(A, m, B, n, r)) / 2.0;
	}
};


int main(void)
{
	Solution sln;

	//auto rtn = sln.findMedianSortedArrays({ 1,3 }, { 2 });

	return 0;
}