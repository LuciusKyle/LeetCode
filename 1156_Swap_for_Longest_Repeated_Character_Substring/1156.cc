
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int maxRepOpt1(const string text) {
    vector<std::pair<int, int>> txt_compress[26];
    int start_recording = 0;
    for (int i = 0; i < text.size(); ++i)
      if (text[i] != text[start_recording]) {
        txt_compress[text[start_recording] - 'a'].push_back(
            {start_recording, i - 1});
        start_recording = i;
      }

    txt_compress[text[start_recording] - 'a'].push_back(
        {start_recording, text.size() - 1});
    int maxRep = 0;
    for (const auto &vec : txt_compress) {
      const int bias1 = 2 < vec.size() ? 1 : 0; // "aba": maxRep is 2, "abaca": maxRep is 3;
      const int bias2 = 1 < vec.size() ? 2 : 1; // "aabba": maxRep is 3, "aabb": maxRep is 2;
      if (!vec.empty() && maxRep < vec[0].second - vec[0].first + bias2)
        maxRep = vec[0].second - vec[0].first + bias2;
      for (int i = 1; i < vec.size(); ++i)
        if (vec[i - 1].second + 2 == vec[i].first) {
          if (maxRep < vec[i].second - vec[i - 1].first + bias1)
            maxRep = vec[i].second - vec[i - 1].first + bias1;
        } else {
          if (maxRep < vec[i].second - vec[i].first + bias2)
            maxRep = vec[i].second - vec[i].first + bias2;
        }
    }
    return maxRep;
  }
};

int main(void) {
  Solution sln;
  int ret = sln.maxRepOpt1("ababa");
  ret = sln.maxRepOpt1("aaaaabbbbbbaabbaabbaaabbbbab");
  return 0;
}
