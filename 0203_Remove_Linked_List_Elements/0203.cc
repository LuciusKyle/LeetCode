
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* removeElements(ListNode* head, const int val) {
    ListNode my_head(val + 1);
    my_head.next = head;
    ListNode* temp_ptr = &my_head;
    while (temp_ptr->next != nullptr) {
      if (temp_ptr->next->val == val)
        temp_ptr->next = temp_ptr->next->next;
      else
        temp_ptr = temp_ptr->next;
    }
    return my_head.next;
  }
};

int main(void) {
  Solution sln;
  
  return 0;
}