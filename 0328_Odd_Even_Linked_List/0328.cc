
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    ListNode odd_list(0);
    odd_list.next = head;
    ListNode even_list(0);
    if (head == nullptr || head->next == nullptr) return head;
    even_list.next = head->next;

    ListNode* odd_ptr = head;
    ListNode* even_ptr = head->next;
    while (even_ptr != nullptr) {
      odd_ptr->next = even_ptr->next;
      if (even_ptr->next != nullptr) even_ptr->next = even_ptr->next->next;
      if (odd_ptr->next != nullptr) odd_ptr = odd_ptr->next;
      even_ptr = even_ptr->next;
    }
    if (even_ptr != nullptr) even_ptr->next = nullptr;
    if (even_list.next != nullptr) odd_ptr->next = even_list.next;
    return odd_list.next;
  }
};

int main(void) {
  Solution sln;
  ListNode head(0);
  ListNode n1(1);
  head.next = &n1;
  ListNode n2(2);
  n1.next = &n2;
  ListNode n3(3);
  n2.next = &n3;
  ListNode n4(4);
  n3.next = &n4;
  sln.oddEvenList(&head);
  return 0;
}