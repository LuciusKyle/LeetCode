
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
 public:
  int findLongestChain(vector<vector<int>>& pairs) {
    std::sort(pairs.begin(), pairs.end(),
              [](vector<int>& x_, vector<int>& y_) -> bool {
                return x_.front() < y_.front();
              });
    vector<int> result(pairs.size(), -1);
    const auto iter = pairs.end();
    for (int i = 0; i < pairs.size(); ++i) {
      
    }
    return 1;
  }

 private:
  int findLongestChain(const vector<vector<int>>& pairs, const int cur_index,
                       vector<int>& result) {
    return 0;
  }
};

int main(void) {
  Solution sln;

  const vector<int> test{0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
  auto iter = std::upper_bound(test.begin(), test.end(), 90);
  if (iter == test.end())
    std::cout << "reach end" << std::endl;
  else
    std::cout << test.end() - iter << std::endl;

  return 0;
}

