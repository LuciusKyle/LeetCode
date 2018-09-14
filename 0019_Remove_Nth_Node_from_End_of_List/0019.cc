/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int count = 0;
    if (n == remove_Node(head, n, count))
      return head->next;
    else
      return head;
  }

 private:
  int remove_Node(struct ListNode* cur, const int n_to_remove,
                  int& count_from_end) {
    if (cur->next != nullptr)
      remove_Node(cur->next, n_to_remove, count_from_end);

    ++count_from_end;
    if (count_from_end == n_to_remove + 1) cur->next = cur->next->next;
    return count_from_end;
  }
};

//////////////////////////////////////////////////////////////////////////////////////
// my code only beat 28% of cpp submissions.
// the following if 100% beats code from leetcode.
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* slow(head);
    ListNode* fast(head);

    while (n--) {
      fast = fast->next;
    }

    if (!fast) return head->next;

    while (fast->next) {
      slow = slow->next;
      fast = fast->next;
    }

    slow->next = slow->next->next;

    return head;
  }
};
