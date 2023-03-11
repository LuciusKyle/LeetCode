
#include <limits.h>

#include <vector>

using std::vector;

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
    vector<int> vals;
    while (head != nullptr) {
      vals.push_back(head->val);
      head = head->next;
    }
    vals.push_back(INT_MAX);
    return sortedListToBST(vals.data(), vals.data() + vals.size() - 1);
  }

 private:
  TreeNode *sortedListToBST(int *start, int *end) {
    if (start == end) return nullptr;
    if (end - start == 1) return new TreeNode(*start);
    const int mid_index = (end - start) / 2;
    return new TreeNode(start[mid_index], sortedListToBST(start, start + mid_index), sortedListToBST(start + mid_index + 1, end));
  }
};

void freeTree(TreeNode *node) {
  if (node != nullptr) {
    freeTree(node->left);
    freeTree(node->right);
    delete node;
  }
}

int main(void) {
  ListNode Five(5);
  ListNode Four(4, &Five);
  ListNode Three(3, &Four);
  ListNode Two(2, &Three);
  ListNode One(1, &Two);
  Solution sln;
  freeTree(sln.sortedListToBST(&One));
  return 0;
}