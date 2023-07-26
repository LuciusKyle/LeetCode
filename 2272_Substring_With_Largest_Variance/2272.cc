
#include <assert.h>
#include <limits.h>
#include <oneapi/tbb/parallel_for.h>
#include <string.h>

#include <iostream>
#include <random>
#include <string>
#include <vector>

using std::string;
using std::vector;

// wrong answer.
class Solution {
 public:
  int largestVariance(const string s) {
    int index_dict[26][26];
    for (int row = 0, help_counter = 0; row < 26; ++row)
      for (int column = 0; column < 26; ++column)
        if (row != column)
          index_dict[row][column] = help_counter++;

    int answer = 0;
    short letters_diff_count[26 * 25][2] = {0};
#ifdef __clang__
    short letters_first_appearance[26] = {[0 ... 25] = -1};
#else
    vector<short> letters_first_appearance(26, -1);
#endif
    for (int j = 0; j < s.size(); ++j) {
      const int ch = s[j] - 'a';
      if (letters_first_appearance[ch] == -1)
        letters_first_appearance[ch] = j;
      // compare other letters with 'ch';
      for (int i = 0; i < 26; ++i) {
        if (i == ch) continue;
        ++letters_diff_count[index_dict[i][ch]][1];
        ++letters_diff_count[index_dict[ch][i]][0];
        // compare 'ch' with 'i';
        if (letters_diff_count[index_dict[i][ch]][0] < letters_diff_count[index_dict[i][ch]][1]) {
          letters_diff_count[index_dict[i][ch]][0] = 0;
          letters_diff_count[index_dict[i][ch]][1] = 0;
        }
        // compare 'i' with 'ch';
        if (letters_diff_count[index_dict[ch][i]][0] < letters_diff_count[index_dict[ch][i]][1]) {
          letters_diff_count[index_dict[ch][i]][0] = 0;
          letters_diff_count[index_dict[ch][i]][1] = 0;
        }
        if (letters_first_appearance[i] != -1)
          answer = std::max(answer, std::max(letters_diff_count[index_dict[i][ch]][0] - letters_diff_count[index_dict[i][ch]][1], letters_diff_count[index_dict[ch][i]][0] - letters_diff_count[index_dict[ch][i]][1]));
      }
    }
    return answer;
  }
};

class Solution_correct_but_slow {
 public:
  // int largestVariance(const string s) {
  int largestVariance(const string &s) {
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
      short min_count = SHRT_MAX, max_count = 0;
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

class Solution_official {
 public:
  int largestVariance(const string s) {
    vector<int> counter(26, 0);
    for (char ch : s) {
      counter[ch - 'a']++;
    }
    int globalMax = 0;

    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        // major and minor cannot be the same, and both must appear in s.
        if (i == j || counter[i] == 0 || counter[j] == 0) {
          continue;
        }

        // Find the maximum variance of major - minor.
        char major = 'a' + i;
        char minor = 'a' + j;
        int majorCount = 0;
        int minorCount = 0;

        // The remaining minor in the rest of s.
        int restMinor = counter[j];

        for (char ch : s) {
          if (ch == major) {
            majorCount++;
          }
          if (ch == minor) {
            minorCount++;
            restMinor--;
          }

          // Only update the variance (local_max) if there is at least one minor.
          if (minorCount > 0)
            globalMax = std::max(globalMax, majorCount - minorCount);

          // We can discard the previous string if there is at least one remaining minor
          if (majorCount < minorCount && restMinor > 0) {
            majorCount = 0;
            minorCount = 0;
          }
        }
      }
    }

    return globalMax;
  }
};

constexpr size_t kBufferSize = 1024 * 1024 * 1024;

int main(int argc, char *argv[]) {
  char *buffer = new char[kBufferSize];
  memset(buffer, 0, kBufferSize);
  FILE *fp = fopen("testcase", "rb");
  int file_size = fread(buffer, 1, kBufferSize, fp);
  fclose(fp);

  Solution sln;
  Solution_official sln_corr;
  // sln.largestVariance(string(buffer, file_size));  // answer should be 86;
  assert(2 == sln_corr.largestVariance("baaba"));
  assert(2 == sln.largestVariance("baaba"));
  assert(12 == sln_corr.largestVariance("ykudzhiixwttnvtesiwnbcjmsydidttiyabbwzlfbmmycwjgzwhbtvtxyvkkjgfehaypiygpstkhakfasiloaveqzcywsiujvixcdnxpvvtobxgroznswwwipypwmdhldsoswrzyqthaqlbwragjrqwjxgmftjxqugoonxadazeoxalmccfeyqtmoxwbnphxih"));
  assert(12 == sln.largestVariance("ykudzhiixwttnvtesiwnbcjmsydidttiyabbwzlfbmmycwjgzwhbtvtxyvkkjgfehaypiygpstkhakfasiloaveqzcywsiujvixcdnxpvvtobxgroznswwwipypwmdhldsoswrzyqthaqlbwragjrqwjxgmftjxqugoonxadazeoxalmccfeyqtmoxwbnphxih"));
  assert(3 == sln_corr.largestVariance("aabbbbaa"));
  assert(3 == sln.largestVariance("aabbbbaa"));
  assert(3 == sln.largestVariance("icexiahccknibwuwgi"));
  assert(3 == sln.largestVariance("aababbb"));
  assert(0 == sln.largestVariance("abcde"));
  delete[] buffer;

  std::random_device rd;
  srand(rd());

  for (int i = 0; i < 10000; ++i) {
    string test_str;
    test_str.resize(5);
    for (int j = 0; j < 5; ++j) {
      test_str[j] = 'a' + char(rand() % 2);
    }
    if (sln.largestVariance(test_str) != sln_corr.largestVariance(test_str)) {
      std::cerr << "test_str: " << test_str << "\ncorrect answer: " << sln_corr.largestVariance(test_str) << "\noutput answer: " << sln.largestVariance(test_str) << std::endl;
      abort();
    }
    // assert(sln.largestVariance(test_str) == sln_corr.largestVariance(test_str));
  }

  oneapi::tbb::parallel_for(0, 10000, [&sln, &sln_corr](int i) {
    string test_str;
    test_str.resize(256);
    for (int j = 0; j < 256; ++j) {
      test_str[j] = 'a' + char(rand() % 26);
    }
    assert(sln.largestVariance(test_str) == sln_corr.largestVariance(test_str));
  });
  return 0;
}
