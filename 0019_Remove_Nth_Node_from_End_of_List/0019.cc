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
  ListNode* removeNthFromEnd(ListNode* head, int n) {}
  private:
  int remove_Node(struct ListNode* cur, const int n_to_remove,
                int& count_from_end) {
#ifdef __cplusplus
  if (cur->next != nullptr)
#else
  if (cur->next != NULL)
#endif
    remove_Node(cur->next, n_to_remove, count_from_end);

  ++count_from_end;
  if (count_from_end == n_to_remove + 1) cur->next = cur->next->next;
  return count_from_end;
}
};