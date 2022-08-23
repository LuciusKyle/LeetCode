
#include <vector>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// it's impossable to solve this problem using constant space without modifying the list.
class Solution {
 public:
  bool isPalindrome(ListNode *head) {
    int node_count = 0;
    ListNode *temp_ptr = head;
    while (temp_ptr != nullptr) {
      ++node_count;
      temp_ptr = temp_ptr->next;
    }
    if (node_count == 1) return true;
    temp_ptr = nullptr;
    ListNode *next_ptr = head;
    for (int i = 0; i < node_count / 2; ++i) {
      ListNode *pre_ptr = temp_ptr;
      temp_ptr = next_ptr;
      next_ptr = next_ptr->next;
      temp_ptr->next = pre_ptr;
    }
    ListNode auxiliary_node(node_count % 2 ? next_ptr->val : temp_ptr->val);
    auxiliary_node.next = node_count % 2 ? temp_ptr : temp_ptr->next;
    temp_ptr = &auxiliary_node;
    while (temp_ptr != nullptr) {
      if (temp_ptr->val != next_ptr->val) return false;
      temp_ptr = temp_ptr->next;
      next_ptr = next_ptr->next;
    }
    return true;
  }
};
