
#include<iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {}

 public:
  ListNode *reverse(ListNode *node, const int count, const int k){
    if(count == k){
      return node;
    }
    node = reverse(node->next, count + 1, k);
    return node;
  }
};

int main(void)
{
  Solution sln;
  ListNode *head = new ListNode(1);
  ListNode *working_ptr = head;
  for (size_t i = 1; i < 5; ++i) {
    working_ptr->next = new ListNode(i + 1);
    working_ptr = working_ptr->next;
  }
  ListNode *rtn = sln.reverse(head, 1, 5);

  return 0;
}