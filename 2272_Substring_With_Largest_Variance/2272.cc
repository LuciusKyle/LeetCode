
#include <assert.h>
#include <limits.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int largestVariance(const string s) {
    vector<LetterCount> letter_count;
    letter_count.reserve(s.size() + 1);
    LetterCount temp_count;
    letter_count.push_back(temp_count);
    int answer = 0;
    for (const char ch : s) {
      ++temp_count.letters[ch - 'a'];
      for (const auto &prefix_count : letter_count) {
        auto substring_count = temp_count - prefix_count;
        answer = std::max(answer, substring_count.maxDiff());
      }
      letter_count.push_back(temp_count);
    }
    return answer;
  }

 private:
  struct LetterCount {
    LetterCount() : letters{0} {}
    short letters[26];
    LetterCount operator-(const LetterCount &sub) {
      LetterCount ret;
      for (int i = 0; i < std::end(letters) - std::begin(letters); ++i) {
        ret.letters[i] = this->letters[i] - sub.letters[i];
      }
      return ret;
    }
    int maxDiff() const {
      short min_count = SHRT_MAX , max_count = 0;
      for (int i = 0; i < std::end(letters) - std::begin(letters); ++i) {
        if (letters[i] != 0) {
          min_count = std::min(min_count, letters[i]);
          max_count = std::max(max_count, letters[i]);
        }
      }
      return max_count - min_count;
    }
  };
};

constexpr size_t kBufferSize = 1024 * 1024 * 1024;

int main(int argc, char *argv[]) {
  char* buffer = new char[kBufferSize];
  memset(buffer, 0, kBufferSize);
  FILE* fp = fopen("testcase", "rb");
  int file_size = fread(buffer, 1, kBufferSize, fp);
  fclose(fp);

  Solution sln;
  sln.largestVariance(string(buffer, file_size));
  assert(3 == sln.largestVariance("icexiahccknibwuwgi"));
  assert(3 == sln.largestVariance("aababbb"));
  assert(0 == sln.largestVariance("abcde"));
  delete[] buffer;
  return 0;
}
