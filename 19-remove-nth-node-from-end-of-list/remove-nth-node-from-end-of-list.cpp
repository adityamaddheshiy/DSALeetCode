/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        // treves not nth steps 
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
       

        // fast is null then remove head ;
        if (fast == NULL) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        // move bhot pointer last until the fast not the last
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // delete nth node from last

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return head;
    }
};