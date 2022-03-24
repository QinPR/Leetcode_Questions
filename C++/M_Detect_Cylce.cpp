// Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.

// Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so as to make a loop in the linked list.

// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1

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
    ListNode *detectCycle(ListNode *head) {
        if (head==NULL||head->next == NULL){
            return NULL;
        }
        ListNode * fast = head->next->next;
        ListNode * slow = head->next;
        bool no_cycle = true;
        while(fast != NULL && slow != NULL){
            if (fast == slow){
                no_cycle = false;
                break;
            }else{
                if (fast->next == NULL || fast->next->next == NULL || slow->next == NULL){
                    break;
                }
                fast = fast->next->next;
                slow = slow->next;
            }
        }
        if (no_cycle) return NULL;
        fast = head;
        while (fast != slow){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
