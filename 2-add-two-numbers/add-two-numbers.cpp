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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL and l1->next == NULL) {
            return l1;
        }
        if (l2 == NULL and l2->next == NULL) {
            return l2;
        }
        ListNode* anshead = NULL;
        ListNode* anstail = NULL;

        int carry =0;

        while (l1 != NULL && l2 != NULL) {
            int sum = carry + l1->val + l2->val;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            if (anshead == NULL) {
                anshead = newNode;
                anstail = newNode;
            } else {
                anstail->next = newNode;
                anstail = newNode;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            int sum = carry + l1->val;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            anstail->next = newNode;
            anstail = newNode;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            int sum = carry + l2->val;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            anstail->next = newNode;
            anstail = newNode;
            l2 = l2->next;
        }

        while (carry != 0) {
            int sum = carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            anstail->next = newNode;
            anstail = newNode;
        }

        return anshead;

    }
};