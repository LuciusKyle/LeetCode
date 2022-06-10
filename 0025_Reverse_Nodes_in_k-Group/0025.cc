
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *reverseKGroup(ListNode *head, const int k) {
    ListNode ret_head(0);
    ret_head.next = head;
    ListNode *pre_tail = &ret_head, *cur_head = head, *cur_ptr = head;
    int node_count = 1;
    while (cur_ptr) {
      if (node_count == k) {
        ListNode *pre_node = pre_tail, *cur_node = cur_head, *next_node = cur_node->next;
        while (cur_node != cur_ptr) {
          cur_node->next = pre_node;
          pre_node = cur_node;
          cur_node = next_node;
          next_node = next_node->next;
        }
        cur_ptr->next = pre_node;
        pre_tail->next = cur_node;
        cur_head->next = next_node;
        cur_ptr = cur_head;
        pre_tail = cur_head;
        cur_head = next_node;
        node_count = 0;
      }
      cur_ptr = cur_ptr->next;
      ++node_count;
    }
    return ret_head.next;
  }
};

int main(void) {
  ListNode node1(1), node2(2), node3(3), node4(4), node5(5);
  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node4;
  node4.next = &node5;
  Solution sln;
  sln.reverseKGroup(&node1, 2);

  return 0;
}