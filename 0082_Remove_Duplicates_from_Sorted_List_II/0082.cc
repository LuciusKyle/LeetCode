
#include<vector>
#include<limits.h>

using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

///////////////////////////////////////////////////////////
//0083
//class Solution {
//public:
//	ListNode* deleteDuplicates(ListNode* head) {
//		int pre_val = head == nullptr ? 0 : head->val + 1; // why (head->val + 1)? so that pre_val != head->val.
//		ListNode *ptr = head;
//		ListNode *pre_ptr = nullptr;
//		while (ptr != nullptr) {
//			if (ptr->val == pre_val)
//				pre_ptr->next = ptr->next;
//			else {
//				pre_ptr = ptr;
//				pre_val = ptr->val;
//			}
//			ptr = ptr->next;
//		}
//		return head;
//	}
//};

///////////////////////////////////////////////////////////
//0082
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		int pre_val = head == nullptr ? 0 : head->val + 1; // why (head->val + 1)? so that pre_val != head->val.
		ListNode *ptr = head;
		vector<int> duplicated_val;
		while (ptr != nullptr) {
			if (ptr->val == pre_val) {
				if (duplicated_val.empty() || duplicated_val.back() != pre_val)
					duplicated_val.push_back(pre_val);
			}
			else
				pre_val = ptr->val;
			ptr = ptr->next;
		}

		size_t vec_index = 0;
		ListNode temp(head == nullptr ? 0 : head->val + 1); // why (head->val + 1)? so that temp.val != head->val.
		temp.next = head;
		ListNode *pre_ptr = &temp;
		ptr = head;
		while (ptr != nullptr && vec_index < duplicated_val.size()) {
			if (duplicated_val[vec_index] < ptr->val) {
				++vec_index;
				continue;
			}
			if (ptr->val < duplicated_val[vec_index]) {
				pre_ptr = ptr;
				ptr = ptr->next;
				continue;
			}
			
			// ptr->val == duplicated_val[vec_index];
			ListNode *next_valid = ptr;
			while (next_valid != nullptr && next_valid->val == duplicated_val[vec_index])
				next_valid = next_valid->next;
			pre_ptr->next = next_valid;
			ptr = next_valid;
		}
		return temp.next;
	}
};

int main(void) {
	Solution sln;
	vector node_list{ new ListNode(1) ,new ListNode(2) ,new ListNode(2) ,new ListNode(3) };
	for (size_t i = 1; i < node_list.size(); ++i) node_list[i - 1]->next = node_list[i];
	

	ListNode *rtn = sln.deleteDuplicates(node_list[0]);
	rtn = sln.deleteDuplicates(nullptr);
	node_list = vector<ListNode *>{ new ListNode(INT_MIN) ,new ListNode(2147483647) ,new ListNode(2) };
	for (size_t i = 1; i < node_list.size(); ++i) node_list[i - 1]->next = node_list[i];
	rtn = sln.deleteDuplicates(node_list[0]);

	return 0;
}
