// Method to merge two singly-linked lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void insertBack(ListNode *&l1, int elem){
        if (l1 == nullptr){
            l1 = new ListNode(elem);
            l1->next = nullptr;
        }
        else {
            ListNode *ptr = l1;
            while(ptr->next != nullptr){
                ptr = ptr->next;
            }
            ptr->next = new ListNode(elem);
            ptr->next->next = nullptr;
        }
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ptr1 = l1;
        ListNode *ptr2 = l2;
        ListNode *head = nullptr;

        while(ptr1 != nullptr && ptr2 != nullptr){
            if (ptr1->val == ptr2->val) {
                insertBack(head, ptr1->val);
                insertBack(head, ptr2->val);
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            else if (ptr1->val < ptr2->val) {
                insertBack(head, ptr1->val);
                ptr1 = ptr1->next;
            }
            else {
                insertBack(head, ptr2->val);
                ptr2 = ptr2->next;
            }
        }
        while(ptr1 != nullptr) {
            insertBack(head, ptr1->val);
            ptr1 = ptr1->next;
        }
        while(ptr2 != nullptr) {
            insertBack(head, ptr2->val);
            ptr2 = ptr2->next;
        }
        return head;
    }
};
