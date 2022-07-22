
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
  ListNode* partition(ListNode* head, int x) {
    ListNode smaller_head, greater_head;
    ListNode *smaller_ptr = &smaller_head, *greater_ptr = &greater_head, *temp_ptr = head;
    while (temp_ptr) {
      if (temp_ptr->val < x) {
        smaller_ptr->next = temp_ptr;
        smaller_ptr = temp_ptr;
      } else {
        greater_ptr->next = temp_ptr;
        greater_ptr = temp_ptr;
      }
      temp_ptr = temp_ptr->next;
    }
    if (greater_ptr == &greater_head)
      return head;
    greater_ptr->next = nullptr;
    smaller_ptr->next = greater_head.next;
    return smaller_head.next;
  }
};