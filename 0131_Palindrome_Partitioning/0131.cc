
#include <string>
#include <vector>
#include<assert.h>

using std::string;
using std::vector;

class Solution {
public:
	int minCut(string s) {
		return 0;
	}

	vector<vector<string>> partition(const string s) {
		vector<vector<string>> rtn;

	}
private:
 void partition(const char *str, const size_t str_size, vector<string> buf, vector<vector<string>> rtn) {
	 for(size_t i = 1;i<str_size;++i){
		 if(str_size-i==1){
			 
		 }
	 }
 }

 bool isPalindrome(const char *str, const size_t str_size) {
   size_t tail_index = str_size - 1;
   char tail_str[sizeof(size_t)] = {'\0'};
   size_t head_index = 0;

   while (head_index < tail_index &&
          2 * sizeof(size_t) < tail_index - head_index) {
     for (size_t i = 0; i < sizeof(size_t); ++i) {
       tail_str[i] = str[tail_index - i];
     }
     if (*(reinterpret_cast<const size_t *>(str + head_index)) !=
         *(reinterpret_cast<const size_t *>(tail_str)))
       return false;
     head_index += sizeof(size_t);
     tail_index -= sizeof(size_t);
   }
   while (head_index < tail_index) {
     if (str[head_index] != str[tail_index]) return false;
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

template <typename T>
T min_of_three(const T t1, const  T t2, const  T t3) {
  return t1 < (t2 < t3 ? t2 : t3) ? t1 : (t2 < t3 ? t2 : t3);
}

int main(void) {
  char test[8] = {"abcedfg"};
  char test2[8] = {"abcedfg"};
  bool rtn = same_string(reinterpret_cast<size_t>(test),
                         reinterpret_cast<size_t>(test2));

  const char test3[16] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
  rtn = Palindrome(test3, 16);
  assert(1 == min_of_three(1, 2, 3));
  assert(1 == min_of_three(2, 1, 3));
  assert(1 == min_of_three(3, 1, 2));
  assert(1 == min_of_three(3, 2, 1));
  return 0;
}
