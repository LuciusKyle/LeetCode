
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
 public:
  vector<vector<string>> suggestedProducts(vector<string>& products, const string searchWord) {
    std::sort(products.begin(), products.end());
    vector<vector<string>> results(searchWord.size());
    for (const string word : products)
      for (int i = 0; i < word.size() && i < searchWord.size(); ++i)
        if (word[i] == searchWord[i]) {
          if (results[i].size() < 3)
            results[i].push_back(word);
        } else
          break;

    return results;
  }
};

int main(int argc, char* argv[]) {
  const string left = 1 < argc ? argv[1] : "abc";
  const string right = 2 < argc ? argv[2] : "abca";
  if (left < right)
    cout << left << " < " << right;
  else if (right < left)
    cout << right << " < " << left;
  cout << endl;
  return 0;
}