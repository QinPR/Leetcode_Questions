// 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

// 请你将两个数相加，并以相同形式返回一个表示和的链表。

// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头

// 输入：l1 = [2,4,3], l2 = [5,6,4]
// 输出：[7,0,8]
// 解释：342 + 465 = 807.

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
        int carry = 0;
        int current_number;
        int head = 1;
        int l1_val = 0;
        int l2_val = 0;
        ListNode* answer = new ListNode(0);
        ListNode* current_node = new ListNode(0);
        while (l1 != nullptr || l2 != nullptr || carry == 1){
            if (l1 != nullptr){
                l1_val = l1->val;
                l1 = l1->next;
            }else{
                l1_val = 0;
            }
            if (l2 != nullptr){
                l2_val = l2->val;
                l2 = l2->next;
            }else{
                l2_val = 0;
            }
            current_number = (l1_val + l2_val + carry) % 10;
            if ((l1_val + l2_val + carry) >= 10) carry = 1;
            else carry = 0;
            if (head == 1){      // the first node of the list
                head = 0;
                answer->val = current_number;
                if (l1 != nullptr || l2 != nullptr || carry == 1) answer->next = current_node;
            }else{
                ListNode* next_node = new ListNode();
                current_node->val = current_number;
                if (l1 != nullptr || l2 != nullptr || carry == 1){
                    current_node->next = next_node;
                }
                current_node = next_node;
            }
        }
        return answer;
    }
};
