// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
// Input: head = [1,2,3,4]
// Output: [2,1,4,3]
// Input: head = [1]
// Output: [1]


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
    ListNode* swapPairs(ListNode* head) {
        ListNode* current_node = head;
        while(current_node != nullptr && current_node->next != nullptr){
            int left_val = current_node->val;
            current_node->val = current_node->next->val;
            current_node->next->val = left_val;
            current_node = current_node->next->next;
        }
        return head;
    }
};
