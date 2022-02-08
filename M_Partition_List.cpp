// Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x. If x is contained within the list, the values of x only need to be after the elements less than x (see below). The partition element x can appear anywhere in the "right partition"; it does not need to appear between the left and right partitions.
// Input: head = 3->5->8->5->10->2->1, x = 5
// Output: 3->1->2->10->5->5->8

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
    ListNode* partition(ListNode* head, int x) {
        ListNode * return_head = new ListNode(x);
        ListNode * init_left;
        bool get_left = false;
        ListNode * tail = return_head;
        ListNode * next_head;
        while (head != NULL){
            if (head->val < x){  // means now the node should be placed to left
                next_head = head->next;
                head->next = return_head;
                return_head = head;
                head = next_head;
                if (!get_left){
                    get_left = true;
                    init_left = return_head;
                }
            }else{   // the node should be placed to right side
                tail->next = head;
                head = head->next;
                tail = tail->next;
                tail->next = NULL;
            }
        }
        if (get_left){
            init_left->next = init_left->next->next;
        }else{
            return_head = return_head->next;
        }
        return return_head;
    }
};
