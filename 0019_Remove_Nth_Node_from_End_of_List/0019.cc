

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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode my_head(0, head);
    ListNode* head_ptr = &my_head;
    ListNode* curr_ptr = &my_head;
    for (int i = 0; i <= n; ++i) {
      curr_ptr = curr_ptr->next;
    }
    while (curr_ptr != nullptr) {
      head_ptr = head_ptr->next;
      curr_ptr = curr_ptr->next;
    }
    head_ptr->next = head_ptr->next->next;
    return my_head.next;
  }
};
