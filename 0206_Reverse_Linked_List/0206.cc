

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode *next_ptr = head;
    ListNode *pre_ptr = nullptr;
    while (head) {
      next_ptr = head->next;
      head->next = pre_ptr;
      pre_ptr = head;
      head = next_ptr;
    }
    return pre_ptr;
  }
};