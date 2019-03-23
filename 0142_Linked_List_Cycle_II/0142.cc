
#include <unordered_set>

using std::unordered_set;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// use hash table.
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode *> ptrs;
    while (head != nullptr)
      if (ptrs.insert(head).second)
        head = head->next;
      else
        return head;
    return nullptr;
  }

 private:
  // leetcode problem 0141.
  bool hasCycle(ListNode *head) {
    unordered_set<ListNode *> ptrs;
    while (head != nullptr)
      if (ptrs.insert(head).second)
        head = head->next;
      else
        return true;
    return false;
  }
};

// use two pointer.
class Solution2 {
 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast_ptr = head;
    ListNode *slow_ptr = head;
    while (true) {
      if (fast_ptr == nullptr || fast_ptr->next == nullptr) return nullptr;
      fast_ptr = fast_ptr->next->next;
      slow_ptr = slow_ptr->next;
      if (fast_ptr == slow_ptr) break;
    }
    while (head != slow_ptr) {
      head = head->next;
      slow_ptr = slow_ptr->next;
    }
    return slow_ptr;  // never reach here.
  }
};
