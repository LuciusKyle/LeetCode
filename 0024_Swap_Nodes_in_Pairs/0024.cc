
#include <stdlib.h>

#include <vector>

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
  ListNode *swapPairs(ListNode *head) {
    ListNode dummy_head(0, head), *pre_ptr = &dummy_head, *curr_ptr = head, *next_ptr = head == nullptr ? nullptr : head->next;
    while (next_ptr != nullptr) {
      pre_ptr->next = next_ptr;
      curr_ptr->next = next_ptr->next;
      next_ptr->next = curr_ptr;
      pre_ptr = curr_ptr;
      curr_ptr = pre_ptr->next;
      next_ptr = curr_ptr == nullptr ? nullptr : curr_ptr->next;
    }
    return dummy_head.next;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);

  Solution sln;
  ListNode *rtn_head = sln.swapPairs(head);
  while (rtn_head) {
    ListNode *temp_node = rtn_head->next;
    delete rtn_head;
    rtn_head = temp_node;
  }
  return 0;
}