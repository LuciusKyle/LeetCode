

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};


#include <vector>
#include <random>

using std::vector;

class Solution {
 public:
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least
     one node. */
  Solution(ListNode* head) {
    while (head != nullptr) {
      number_cache_.push_back(head->val);
      head = head->next;
    }
    dist.param(decltype(dist)::param_type{0, number_cache_.size() - 1});
  }

  /** Returns a random node's value. */
  int getRandom() {
    return number_cache_[dist(rd)];
  }

 private:
  vector<int>number_cache_;
  std::uniform_int_distribution<size_t> dist;
  std::random_device rd;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main(void) { return 0; }