
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
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		auto node_1 = l1, node_2 = l2;
		ListNode *node_rtn = nullptr;
		ListNode *current_ptr = nullptr;
		bool carry = false;
		while (node_1 != nullptr && node_2 != nullptr) {
			int val = (node_1 == nullptr ? 0 : node_1->val) + (node_2 == nullptr ? 0 : node_2->val) + (carry ? 1 : 0);
			if (val > 10) {
				carry = true;
				val %= 10;
			}
			else {
				carry = false;
			}
			current_ptr = new ListNode(val);
		}
	}
};


int main(int argc, char *argv[])
{

	return 0;
}
