
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
  ListNode* reverseList(ListNode* head) {
    ListNode *pre_node = nullptr, *curr_node = head, *next_node = head == nullptr ? nullptr : head->next;
    while (curr_node != nullptr) {
      curr_node->next = pre_node;
      pre_node = curr_node;
      curr_node = next_node;
      if (next_node != nullptr) next_node = next_node->next;
    }
    return pre_node;
  }
};
