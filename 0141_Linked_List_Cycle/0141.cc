

#include <unordered_set>

using std::unordered_set;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// my solution.
class Solution {
 public:
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

// official suggested solution.
class Solution0 {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) { return false; }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow != fast){
            if (fast == nullptr || fast->next == nullptr){
                return false; 
            }
            slow = slow->next;
            fast = fast->next->next; 
        }
        return true; 
    }
};
