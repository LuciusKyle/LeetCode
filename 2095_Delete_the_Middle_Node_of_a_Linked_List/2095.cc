
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* deleteMiddle(ListNode* head) {
    ListNode my_head(0, head);
    ListNode *fast_ptr = head, *slow_ptr = &my_head;
    bool next_slow = false;
    while (fast_ptr != nullptr) {
      fast_ptr = fast_ptr->next;
      if (next_slow) {
        slow_ptr = slow_ptr->next;
        next_slow = false;
      } else
        next_slow = true;
    }
    slow_ptr->next = slow_ptr->next->next;  // possible memory leak;
    return my_head.next;
  }
};