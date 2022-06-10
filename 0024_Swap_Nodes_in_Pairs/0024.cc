
#include <stdlib.h>
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
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *cur_node = head, *next_node = head == nullptr ? nullptr : head->next;
    // use recursion.
    // if no recursion, then 4 pointers are needed.
    next_node->next = swapPairs(next_node->next);

    cur_node->next = next_node->next;
    next_node->next = cur_node;
    return next_node;
  }
};

int main(int argc, char * argv[] ) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);

  Solution sln;
  ListNode * rtn_head = sln.swapPairs(head);
  while (rtn_head) {
    ListNode *temp_node = rtn_head->next;
    delete rtn_head;
    rtn_head = temp_node;
  }
  return 0;
}