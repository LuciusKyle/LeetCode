
#include <iostream>

using std::cout;
using std::endl;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution_0025 {
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

class Solution {
 public:
  ListNode *reverseEvenLengthGroups(ListNode *head) {
    ListNode ret_head(0);
    ret_head.next = head;
    ListNode *pre_tail = &ret_head, *cur_head = head, *cur_ptr = head;
    int node_count = 1;
    int k = 1;
    while (cur_ptr->next) {
      if (node_count == k) {
        if (k % 2 == 0) {
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
        } else {
          cur_head = cur_ptr->next;
          pre_tail = cur_ptr;
        }
        node_count = 0;
        ++k;
      }
      cur_ptr = cur_ptr->next;
      ++node_count;
    }
    if (node_count != 0 && node_count % 2 == 0) {
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
  sln.reverseEvenLengthGroups(&node1);

  return 0;
}