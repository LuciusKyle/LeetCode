
#include <iostream>
#include <string>
#include <array>
#include <assert.h>

using std::string;

#if 201402L < __clpusplus
constexpr std::array Alphabet_Chart{ '?', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
#else
constexpr std::array<char, 27> Alphabet_Chart{ '?', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
#endif

class Solution {
public:
	string convertToTitle(int n) {
		string reverse_rtn;
		while (n > 0) {
			--n;
			reverse_rtn.push_back(Alphabet_Chart[n % 26 + 1]);
			n /= 26;
		}
		return { reverse_rtn.crbegin(), reverse_rtn.crend() };
	}
};

int main(void)
{
	Solution sln;
	for (int i = 1; i <= 100; ++i) {
		std::cout << i << '\t' << sln.convertToTitle(i) << std::endl;
	}
	return 0;
}

