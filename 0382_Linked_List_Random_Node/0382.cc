
#include <time.h>

#include <random>
#include <vector>

using std::vector;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  Solution(ListNode *head) {
    do {
      vals_.push_back(head->val);
      head = head->next;
    } while (head != nullptr);
    srand(time(nullptr));
  }

  int getRandom() { return vals_[rand() % vals_.size()]; }

 private:
  vector<int> vals_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */