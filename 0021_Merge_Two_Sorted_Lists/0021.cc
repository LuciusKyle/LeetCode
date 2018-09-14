

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// memory leak version;
class Solution_Memory_Leak {
 public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *ptr_1 = l1;
    ListNode *ptr_2 = l2;

    ListNode *head = new ListNode(0);
    ListNode *cur_ptr = head;
    while (ptr_1 != nullptr || ptr_2 != nullptr) {
      if (ptr_1 == nullptr) {
        cur_ptr->next = new ListNode(ptr_2->val);
        ptr_2 = ptr_2->next;
        cur_ptr = cur_ptr->next;
        continue;
      }
      if (ptr_2 == nullptr) {
        cur_ptr->next = new ListNode(ptr_1->val);
        ptr_1 = ptr_1->next;
        cur_ptr = cur_ptr->next;
        continue;
      }
      if (ptr_1->val < ptr_2->val)
        cur_ptr->next = new ListNode(ptr_1->val);
      else
        cur_ptr->next = new ListNode(ptr_2->val);
      cur_ptr = cur_ptr->next;
    }
    cur_ptr = head->next;
    delete head;
    return cur_ptr;
  }
};

// my 80% beats solution. 
class Solution {
 public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if(l1 == nullptr && l2 == nullptr) return nullptr;
    ListNode *ptr_1 = l1;
    ListNode *ptr_2 = l2;
    ListNode *head_ptr = new ListNode(0);
    ListNode *working_ptr = head_ptr;

    while (ptr_1 != nullptr || ptr_2 != nullptr) {
      do {
        if (ptr_1 == nullptr) {
          working_ptr->next = ptr_2;
          ptr_2 = ptr_2->next;
          break;
        }
        if (ptr_2 == nullptr) {
          working_ptr->next = ptr_1;
          ptr_1 = ptr_1->next;
          break;
        }
        if(ptr_1->val < ptr_2->val){
          working_ptr->next = ptr_1;
          ptr_1 = ptr_1->next;
        }else{
          working_ptr->next = ptr_2;
          ptr_2 = ptr_2->next;
        }
      } while (false);
      working_ptr = working_ptr->next;
    }
    working_ptr = head_ptr->next;
    delete head_ptr;
    return working_ptr;
  }
};

// offical site solution.
class Solution_offical {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};