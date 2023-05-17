
#include <algorithm>

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
  int pairSum(ListNode *head) {
    ListNode dummy_head(0, head), *fast_ptr = head, *slow_ptr = head, *pre_slow_ptr = &dummy_head, *slow_next = head;
    do {
      fast_ptr = fast_ptr->next->next;
      slow_next = slow_ptr->next;
      slow_ptr->next = pre_slow_ptr;
      pre_slow_ptr = slow_ptr;
      slow_ptr = slow_next;
    } while (fast_ptr != nullptr);
    // now pre_slow_ptr is at 2/n node.
    int answer = pre_slow_ptr->val + slow_ptr->val;
    while (pre_slow_ptr != &dummy_head) {
      answer = std::max(answer, slow_ptr->val + pre_slow_ptr->val);
      slow_ptr = slow_ptr->next;
      pre_slow_ptr = pre_slow_ptr->next;
    }
    return answer;
  }
};
