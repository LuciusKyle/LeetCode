
#include <stack>
#include <vector>

using std::stack;
using std::vector;

class Solution {
 public:
  vector<int> canSeePersonsCount(const vector<int>& heights) {
    vector<int> answer(heights.size());
    stack<int> visiable_queue;
    for (int i = int(heights.size()) - 1; 0 <= i; --i) {
      int visiable_count = 0;
      while (!visiable_queue.empty() && visiable_queue.top() < heights[i]) {
        ++visiable_count;
        visiable_queue.pop();
      }
      answer[i] = visiable_count + (visiable_queue.empty() ? 0 : 1);
      visiable_queue.push(heights[i]);
    }
    return answer;
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  vector<int> test_vec{5, 1, 2, 3, 10};
  auto ret_vec = sln.canSeePersonsCount(test_vec);
  return 0;
}