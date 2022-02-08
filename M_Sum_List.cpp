// You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.
// Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295.
// Output: 2 -> 1 -> 9. That is, 912.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode();
        ListNode* current = answer;
        int carry = 0;
        bool head = 1;
        int l1_val, l2_val;
        while (l1 != NULL || l2 != NULL || carry != 0){
            if (l1 == NULL && l2 == NULL && carry != 0){
                current->next = new ListNode(carry);
                return answer;
            }
            if (l1 == NULL){
                l1_val = 0;
                l2_val = l2->val;
                l2 = l2->next;
            }
            else if (l2 == NULL){
                l1_val = l1->val;
                l2_val = 0;
                l1 = l1->next;
            }else{
                l1_val = l1->val;
                l2_val = l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            int sum = l1_val + l2_val + carry;
            if (head){
                answer->val = sum%10;
                head = false;
            }else{
                current->next = new ListNode(sum%10);
                current = current->next;
            }
            if (sum >= 10) carry = 1;
            else carry = 0;
        }
        return answer;
    }
};
