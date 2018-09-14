
#include <limits.h>
#include <list>
#include <vector>

using std::list;
using std::vector;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

// very bad runtime. 3% beat of cpp submissions.
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* head = new ListNode(0);
    ListNode* working_ptr = head;
    while (!all_nullptr(lists)) {
      int min_index = -1;
      int min_val = INT_MAX;
      for (int i = 0; i < lists.size(); ++i)
        if (lists[i] != nullptr)
          if (lists[i]->val < min_val) {
            min_val = lists[i]->val;
            min_index = i;
          }
      working_ptr->next = lists[min_index];
      working_ptr = working_ptr->next;
      lists[min_index] = lists[min_index]->next;
    }
    working_ptr = head->next;
    delete head;
    return working_ptr;
  }
 private:
  bool all_nullptr(const vector<ListNode*>& lists) const {
    for (const auto ptr : lists)
      if (ptr != nullptr) return false;
    return true;
  }
};