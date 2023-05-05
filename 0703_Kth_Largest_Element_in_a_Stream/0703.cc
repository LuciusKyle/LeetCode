
#include <queue>
#include <vector>

using std::vector;

class KthLargest {
 public:
  KthLargest(int k, vector<int>& nums) : k_(k), pq_(nums.begin(), nums.end()) {
    while (pq_.size() > k) pq_.pop();
  }

  int add(int val) {
    pq_.push(val);
    if (k_ < pq_.size())
      pq_.pop();
    return pq_.top();
  }

 private:
  const int k_;
  std::priority_queue<int, vector<int>, std::greater<int>> pq_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */