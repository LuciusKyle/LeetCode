
#include <list>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  int minMutation(string start, string end, vector<string>& bank) {
    vector<string> current_level;
    std::list<string> remain_bank;
    remain_bank.push_back(string());
    for (const string& gene : bank) {
      switch (geneDiff(start, gene)) {
        case 0:
          break;
        case 1:
          current_level.push_back(gene);
          if (gene == end) return 1;
          break;
        default:
          remain_bank.push_back(gene);
          break;
      }
    }
    // bank.clear();
    int level = 1;
    while (!current_level.empty()) {
      ++level;
      vector<string> next_level;
      for (const string& gene : current_level) {
        auto iter = remain_bank.begin();
        ++iter;
        for (; iter != remain_bank.end(); ++iter) {
          if (1 == geneDiff(gene, *iter)) {
            if (*iter == end) return level;
            next_level.push_back(*iter);
            iter = remain_bank.erase(iter);
            --iter;
          }
        }
      }
      current_level = next_level;
    }
    return -1;
  }

 private:
  int geneDiff(const string& gene1, const string& gene2) {
    int result = 0;
    for (int i = 0; i < 8; ++i) {
      if (gene1[i] != gene2[i]) ++result;
    }
    return result;
  }
};
