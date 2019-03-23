
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// this is my solution, 99% beat. best solution is "circle the link", tail_ptr->next = head;
class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    ListNode my_head(0);
    my_head.next = head;
    int count = 0;
    int list_length = 0;
    ListNode* ptr = &my_head;
    ListNode* ptr2 = &my_head;

    while (ptr->next != nullptr) {
      list_length++;
      ptr = ptr->next;
      if (count == k) {
        count--;
        ptr2 = ptr2->next;
      }
      ++count;
    }
    if (k < list_length || list_length == 0) {
      ptr->next = my_head.next;
      my_head.next = ptr2->next;
      ptr2->next = nullptr;
      return my_head.next;
    }
    else if (k == list_length) 
     return head;
    k %= list_length;
    ptr = &my_head;
    ptr2 = &my_head;
    count = 0;
    while (ptr->next != nullptr) {
      ptr = ptr->next;
      if (count == k) {
        count--;
        ptr2 = ptr2->next;
      }
      ++count;
    }
    ptr->next = my_head.next;
    my_head.next = ptr2->next;
    ptr2->next = nullptr;
    return my_head.next;
  }
};

int main(void) {
  Solution sln;
  
  return 0;
}
