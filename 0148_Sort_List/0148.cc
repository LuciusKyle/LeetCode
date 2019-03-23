

#include <assert.h>
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
    ListNode* mid_ptr = head;
    ListNode* temp_ptr = head == nullptr ? nullptr : head->next;
    size_t list_length = 0;
    while (temp_ptr != nullptr) {
      if ((list_length & size_t(0x1)) == 1) mid_ptr = mid_ptr->next;
      temp_ptr = temp_ptr->next;
      ++list_length;
    }
    if (list_length == 0) return head;
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
  ListNode* temp_ptr = &head;
  for (size_t i = 0; i < 10000000; ++i) {
    temp_ptr->next = new ListNode(dist(rd));
    // temp_ptr->next = new ListNode(int(i));
    temp_ptr = temp_ptr->next;
  }

  //{
  //       auto ptr3 = head.next->next->next;
  //       auto ptr2 = head.next->next;
  //       auto ptr1 = head.next;
  //       ptr2->next = ptr1;
  //       ptr1->next = ptr3;
  //       head.next = ptr2;
  //}

  Solution sln;
  ListNode* rtn = sln.sortList(head.next);

  while (rtn != nullptr) {
    ListNode* temp_ptr = rtn;
    rtn = rtn->next;
    assert(rtn == nullptr || temp_ptr->val <= rtn->val);
    delete temp_ptr;
  }
  return 0;
}