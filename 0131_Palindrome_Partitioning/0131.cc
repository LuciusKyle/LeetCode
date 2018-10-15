
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
	int minCut(string s) {
		return 0;
	}

	vector<vector<string>> partition(string s) {
		vector<vector<string>> rtn;
	}
private:
	bool isPalindrome(const char *str, size_t str_size) {
		size_t tail_index = str_size - 1;
		char tail_str[sizeof(size_t) + 12] = { '\0' };
		size_t head_index = 0;

		while (head_index < tail_index && 2 * sizeof(size_t) < tail_index - head_index) {
			for (size_t i = 0; i < sizeof(size_t); ++i) {
				tail_str[i] = str[tail_index - i];
			}
			if (*(reinterpret_cast<const size_t *>(str + head_index)) != *(reinterpret_cast<const size_t *>(tail_str)))
				return false;
			head_index += sizeof(size_t);
			tail_index -= sizeof(size_t);
		}
		while (head_index < tail_index) {
			if (str[head_index] != str[tail_index])
				return false;
			++head_index;
			--tail_index;
		}
		return true;
	}
};

bool same_string(const size_t a, const size_t b) {
	return a == b;
}

bool Palindrome(const string str) {
	return false;
}

constexpr size_t v1 = sizeof(size_t);

bool Palindrome(const char *str, size_t str_size) {
	size_t tail_index = str_size - 1;
	char tail_str[sizeof(size_t) + 12] = { '\0' };
	size_t head_index = 0;

	while (head_index < tail_index && 2 * sizeof(size_t) < tail_index - head_index) {
		for (size_t i = 0; i < sizeof(size_t); ++i) {
			tail_str[i] = str[tail_index - i];
		}
		if (*(reinterpret_cast<const size_t *>(str + head_index)) != *(reinterpret_cast<const size_t *>(tail_str)))
			return false;
		head_index += sizeof(size_t);
		tail_index -= sizeof(size_t);
	}
	while (head_index < tail_index) {
		if (str[head_index] != str[tail_index])
			return false;
		++head_index;
		--tail_index;
	}
	return true;
}

int main(void) {
	char test[8] = { "abcedfg" };
	char test2[8] = { "abcedfg" };
	bool rtn = same_string(reinterpret_cast<size_t>(test), reinterpret_cast<size_t>(test2));

	const char test3[16] = { 'a','b','c','d','e','f','g','h','h','g','f','e','d','c','b','a' };
	rtn = Palindrome(test3, 16);

	return 0;
}
