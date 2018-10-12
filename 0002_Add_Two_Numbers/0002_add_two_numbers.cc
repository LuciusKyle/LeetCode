
//
//									Hello World!
//------------------------------------------------------------------------------------------------
//
//						this is a cpp source file.
//
//						Lucius@LUCIUS-PC
//											--4/11/2018 15:15:49
//
//
//			Copyright (c) 2018 LuciusKyle@outlook.com. All rights reserved.
//
//------------------------------------------------------------------------------------------------
//									Goodbye World!
//


//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Example
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//Explanation: 342 + 465 = 807.


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *header = nullptr;
    ListNode *current_ptr = nullptr;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry) {
      const int val = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + carry;
      carry = val / 10;
      auto node_ptr = new ListNode(val % 10);
      if (header == nullptr) {
        header = new ListNode(val % 10);
        current_ptr = header;
      } else {
        current_ptr->next = new ListNode(val % 10);
        current_ptr = current_ptr->next;
      }
      if (l1 != nullptr) {
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        l2 = l2->next;
      }
    }
    return header;
  }
};

void distroy_list(ListNode *node)
{
	if (node == nullptr) {
		return;
	}
	distroy_list(node->next);
	delete node;
}

int main(int argc, char *argv[])
{
	Solution sln;

	ListNode *temp = nullptr;

	ListNode *a = new ListNode(2);
	temp = a;
	temp->next = new ListNode(4);
	temp = temp->next;
	temp->next = new ListNode(3);

	ListNode *b = new ListNode(5);
	temp = b;
	temp->next = new ListNode(6);
	temp = temp->next;
	temp->next = new ListNode(4);

	auto rtn = sln.addTwoNumbers(a, b);

	distroy_list(rtn);
	distroy_list(a);
	distroy_list(b);

	return 0;
}


// a better solution from LeetCode discussion
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	ListNode preHead(0), *p = &preHead;
	int extra = 0;
	while (l1 || l2 || extra) {
		int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
		extra = sum / 10;
		p->next = new ListNode(sum % 10);
		p = p->next;
		l1 = l1 ? l1->next : l1;
		l2 = l2 ? l2->next : l2;
	}
	return preHead.next;
}

