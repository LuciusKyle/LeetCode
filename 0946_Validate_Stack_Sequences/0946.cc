
#include <vector>

using std::vector;

class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    vector<int> simulation;
    simulation.reserve(pushed.size());
    int j = 0;
    for (int i = 0; i < pushed.size(); ++i) {
      simulation.push_back(pushed[i]);
      while (!simulation.empty() && popped[j]==simulation.back()) {
        simulation.pop_back();
        ++j;
      }
    }
    return j == popped.size();
  }
};
