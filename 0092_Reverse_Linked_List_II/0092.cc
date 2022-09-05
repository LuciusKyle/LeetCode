
#include <vector>

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
  ListNode* reverseBetween(ListNode* head, const int left, const int right) {
    if (left == right) return head;
    ListNode my_head(0, head);
    ListNode *pre_ptr = &my_head, *curr_ptr = head;
    for (int i = 1 /* start from 1? */; i < left; ++i) {
      pre_ptr = curr_ptr;
      curr_ptr = curr_ptr->next;
    }
    ListNode *reversed_tail = curr_ptr, *pre_reversed_ptr = pre_ptr;
    for (int i = 0; i <= right - left; ++i) {
      ListNode* temp_ptr = curr_ptr->next;
      curr_ptr->next = pre_ptr;
      pre_ptr = curr_ptr;
      curr_ptr = temp_ptr;
    }
    reversed_tail->next = curr_ptr;
    pre_reversed_ptr->next = pre_ptr;
    return my_head.next;
  }
};