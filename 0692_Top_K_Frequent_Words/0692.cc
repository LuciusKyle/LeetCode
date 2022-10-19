
#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

// this is a O(n log(n)) solution.
// there is a O(n log(k)) time and O(n) extra space solution, using std::priority_queue(or std::set).
class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    std::sort(words.begin(), words.end());
    vector<std::pair<string, int>> frequence_count;
    frequence_count.emplace_back(words[0], 1);
    for (int i = 1; i < words.size(); ++i)
      if (words[i] == words[i - 1])
        ++frequence_count.back().second;
      else
        frequence_count.emplace_back(words[i], 1);
    std::sort(frequence_count.begin(), frequence_count.end(), [](const std::pair<string, int>& _x, const std::pair<string, int>& _y) -> bool {if (_x.second > _y.second)return true;else if (_y.second > _x.second) return false; else return _x.first > _y.first; });
    vector<string> result;
    result.reserve(k);
    for (int i = 0; i < k; ++i)
      result.push_back(frequence_count[i].first);
    return result;
  }
};