
#include <vector>

using std::vector;

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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    vector<ListNode*> temp_ptrs;
    temp_ptrs.reserve(lists.size() / 2 + 1);
    do {
      temp_ptrs.clear();
      if (0 != lists.size() % 2)
        temp_ptrs.push_back(lists.back());
      for (int i = 1; i < lists.size(); i += 2)
        temp_ptrs.push_back(merge2Lists(lists[i - 1], lists[i]));
      lists = temp_ptrs;
    } while (temp_ptrs.size() != 1);
    return temp_ptrs.front();
  }

 private:
  ListNode* merge2Lists(ListNode* _x, ListNode* _y) {
    ListNode dummy_head, *ptr = &dummy_head;
    while (_x != nullptr && _y != nullptr) {
      if (_x->val < _y->val) {
        ptr->next = _x;
        _x = _x->next;
      } else {
        ptr->next = _y;
        _y = _y->next;
      }
      ptr = ptr->next;
    }
    if (_x == nullptr)
      ptr->next = _y;
    else
      ptr->next = _x;
    return dummy_head.next;
  }
};
