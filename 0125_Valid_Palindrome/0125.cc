
#include<string>
#include<cctype>

using std::string;

class Solution {
public:
	bool isPalindrome(const string s) {
		size_t left = 0;
		size_t right = s.size() == 0 ? 0 : s.size() - 1;
		while (left < right) {
			const char ch_left = std::tolower(s[left]);
			const char ch_right = std::tolower(s[right]);
			if (!(('a' <= ch_left && ch_left <= 'z') ||
				('0' <= ch_left && ch_left <= '9'))) {
				++left;
				continue;
			}
			if (!(('a' <= ch_right && ch_right <= 'z') ||
				('0' <= ch_right && ch_right <= '9'))) {
				--right;
				continue;
			}
			if (ch_left == ch_right) {
				++left;
				--right;
			}
			else
				return false;
		}
		return true;
	}
private:
	//bool isPalindrome(const char *str, size_t str_size) {
	//	size_t tail_index = str_size == 0 ? 0 : str_size - 1;
	//	char tail_str[sizeof(size_t) + 12] = { '\0' };
	//	size_t head_index = 0;

	//	while (head_index < tail_index && 2 * sizeof(size_t) < tail_index - head_index) {
	//		for (size_t i = 0; i < sizeof(size_t); ++i) {
	//			tail_str[i] = str[tail_index - i];
	//		}
	//		if (*(reinterpret_cast<const size_t *>(str + head_index)) != *(reinterpret_cast<const size_t *>(tail_str)))
	//			return false;
	//		head_index += sizeof(size_t);
	//		tail_index -= sizeof(size_t);
	//	}
	//	while (head_index < tail_index) {
	//		if (str[head_index] != str[tail_index])
	//			return false;
	//		++head_index;
	//		--tail_index;
	//	}
	//	return true;
	//}
};

int main(void) {

	return 0;
}
