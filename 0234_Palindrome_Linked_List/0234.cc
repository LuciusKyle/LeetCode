
#include <vector>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// it's impossable to solve this problem using constant space and without modifying the list.
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    ListNode* temp_ptr = head;
    std::vector<int> node_vec;
    while (temp_ptr != nullptr) {
      node_vec.push_back(temp_ptr->val);
      temp_ptr = temp_ptr->next;
    }
    for (size_t i = 0; i < node_vec.size() / 2; ++i)
      if (node_vec[i] != node_vec[node_vec.size() - i - 1]) return false;
    return true;
  }
};