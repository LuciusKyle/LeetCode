
constexpr int kModulo = 1'000'000'000 + 7;

// this problem should not be rated as 'hard'.
class Solution {
 public:
  int countVowelPermutation(const int n) {
    int vowel_count[][5] = {{}, {1, 1, 1, 1, 1}};
    for (int i = 1; i < n; ++i) {
      const int new_index = ((i + 1) & 1), old_index = (i & 1);
      vowel_count[new_index][0] = ((vowel_count[old_index][1] + vowel_count[old_index][2]) % kModulo + vowel_count[old_index][4]) % kModulo;
      vowel_count[new_index][1] = (vowel_count[old_index][0] + vowel_count[old_index][2]) % kModulo;
      vowel_count[new_index][2] = (vowel_count[old_index][1] + vowel_count[old_index][3]) % kModulo;
      vowel_count[new_index][3] = vowel_count[old_index][2];
      vowel_count[new_index][4] = (vowel_count[old_index][2] + vowel_count[old_index][3]) % kModulo;
    }
    int answer = 0;
    for (int answer_index = (n & 1), i = 0; i < 5; ++i) {
      answer += vowel_count[answer_index][i];
      answer %= kModulo;
    }
    return answer;
  }
};
