
#include <limits.h>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode *sortedListToBST(ListNode *head) {
    if (head == nullptr) return nullptr;
    return sortedListToBST(head, nullptr);
  }

 private:
  TreeNode *sortedListToBST(ListNode *head, ListNode *tail) {
    ListNode auxiliary_node(INT_MIN, head);
    ListNode *faster_node = &auxiliary_node, *slower_node = &auxiliary_node, *pre_node = &auxiliary_node;
    while (faster_node != tail) {
      pre_node = slower_node;
      slower_node = slower_node->next;
      faster_node = faster_node->next;
      if (faster_node != tail) faster_node = faster_node->next;
    }
    TreeNode *tree_node = new TreeNode(slower_node->val);
    if (slower_node != head) {
      if (head->next == slower_node)
        tree_node->left = new TreeNode(head->val);
      else
        tree_node->left = sortedListToBST(head, slower_node);
    }
    if (slower_node->next != tail)
      tree_node->right = sortedListToBST(slower_node->next, tail);

    return tree_node;
  }
};

int main(void) {
  ListNode Five(5);
  ListNode Four(4, &Five);
  ListNode Three(3, &Four);
  ListNode Two(2, &Three);
  ListNode One(1, &Two);
  Solution sln;
  sln.sortedListToBST(&One);
  return 0;
}