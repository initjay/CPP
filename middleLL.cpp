// Method to return middle node of singly-linked list 

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
    ListNode* middleNode(ListNode* head) {
        if (head == NULL)
            return NULL;

        ListNode* curr = head;
        int count = 0;

        while(curr->next != NULL) {
            curr = curr->next;
            count ++;
        }

        if(count % 2 != 0) {
            count /= 2;
            count ++;
        } else
            count /= 2;

        curr = head;

        for(int i = 0; i < count; i++) {
            curr = curr->next;
        }

        return curr;
    }
};
