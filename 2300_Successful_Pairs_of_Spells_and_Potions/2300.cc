
#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    std::sort(potions.begin(), potions.end());
    for (int i = 0; i < spells.size(); ++i)
      if (success % spells[i] != 0)
        spells[i] = potions.end() - std::upper_bound(potions.begin(), potions.end(), success / spells[i]);
      else
        spells[i] = potions.end() - std::lower_bound(potions.begin(), potions.end(), success / spells[i]);
    return spells;
  }
};

int main(int argc, char* argv[]) {
  vector<int> vec{1, 3, 5, 7, 9};
  auto iter = std::upper_bound(vec.begin(), vec.end(), 2);
  cout << vec.end() - iter << "\n";
  iter = std::upper_bound(vec.begin(), vec.end(), 3);
  cout << vec.end() - iter << "\n";
  iter = std::lower_bound(vec.begin(), vec.end(), 2);
  cout << vec.end() - iter << "\n";
  iter = std::lower_bound(vec.begin(), vec.end(), 3);
  cout << vec.end() - iter << "\n";
  iter = std::lower_bound(vec.begin(), vec.end(), 9);
  cout << vec.end() - iter << "\n";
  iter = std::lower_bound(vec.begin(), vec.end(), 10);
  cout << vec.end() - iter << "\n";
  return 0;
}