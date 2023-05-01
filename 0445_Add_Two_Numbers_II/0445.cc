

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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *reversed_l1 = reverseList(l1), *reversed_l2 = reverseList(l2);
    bool carry_digit = false;
    ListNode answer_list_head(0), *ptr = &answer_list_head;
    while (reversed_l1 != nullptr || reversed_l2 != nullptr) {
      const int val = (reversed_l1 == nullptr ? 0 : reversed_l1->val) + (reversed_l2 == nullptr ? 0 : reversed_l2->val) + (carry_digit ? 1 : 0);
      if (reversed_l1 != nullptr) reversed_l1 = reversed_l1->next;
      if (reversed_l2 != nullptr) reversed_l2 = reversed_l2->next;
      carry_digit = 10 <= val;
      ptr->next = new ListNode(val % 10);
      ptr = ptr->next;
    }
    if (carry_digit) ptr->next = new ListNode(1);
    return reverseList(answer_list_head.next);
  }

 private:
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
