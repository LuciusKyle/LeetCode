

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
  ListNode* swapNodes(ListNode* head, int k) {
    ListNode *pre_kth, *kth, *pre_r_kth, *r_kth;
    ListNode dummy_head(0, head);
    pre_kth = &dummy_head;
    kth = head;
    for (int i = 1; i < k; ++i) {
      pre_kth = kth;
      kth = kth->next;
    }
    ListNode* tail_node = kth;
    pre_r_kth = &dummy_head;
    r_kth = head;
    while (tail_node->next != nullptr) {
      pre_r_kth = r_kth;
      r_kth = r_kth->next;
      tail_node = tail_node->next;
    }
    if (r_kth == kth) return head;
    if (kth->next == r_kth) {
      kth->next = r_kth->next;
      pre_kth->next = r_kth;
      r_kth->next = kth;
      return dummy_head.next;
    }
    if (r_kth->next == kth) {
      r_kth->next = kth->next;
      pre_r_kth->next = kth;
      kth->next = r_kth;
      return dummy_head.next;
    }
    ListNode* temp_kth_next = kth->next;
    kth->next = r_kth->next;
    pre_kth->next = r_kth;
    r_kth->next = temp_kth_next;
    pre_r_kth->next = kth;
    return dummy_head.next;
  }
};

int main(int argc, char* argv[]) {
  ListNode five(5);
  ListNode four(4, &five);
  ListNode three(3, &four);
  ListNode two(2, &three);
  ListNode one(1, &two);

  Solution sln;
  sln.swapNodes(&one, 2);
  return 0;
}