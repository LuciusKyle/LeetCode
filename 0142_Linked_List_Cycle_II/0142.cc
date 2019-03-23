
#include <unordered_set>

using std::unordered_set;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

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