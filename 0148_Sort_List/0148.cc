
#include <limits.h>
#include <random>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    ListNode *mid_ptr = head;
    ListNode *temp_ptr = head;
    size_t list_length = 0;
    while (temp_ptr !=nullptr) {
      if ((list_length & size_t(0x1)) == 0) mid_ptr = mid_ptr->next;
      temp_ptr = temp_ptr->next;
      ++list_length;
    }
    if(list_length < 2) return head;
    temp_ptr = mid_ptr->next;
    mid_ptr->next = nullptr;
    return mergeTwoLists(sortList(head), sortList(temp_ptr));
  }

 private:
  // function from leetcode problem 21.
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode head(INT_MIN);
    ListNode* ptr = &head;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        ptr->next = l1;
        l1 = l1->next;
      } else {
        ptr->next = l2;
        l2 = l2->next;
      }
      ptr = ptr->next;
    }
    if (l1 != nullptr) ptr->next = l1;
    if (l2 != nullptr) ptr->next = l2;
    return head.next;
  }
};

int main(void) {
  ListNode head(0);
  std::random_device rd;
  std::uniform_int_distribution<int> dist(-10000, 10000);
  ListNode *temp_ptr = &head;
  for(size_t i = 0;i<1000;++i){
    temp_ptr->next = new ListNode(dist(rd));
    temp_ptr = temp_ptr->next;
  }

  Solution sln;
  sln.sortList(&head);


  return 0;
}

