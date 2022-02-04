// T1 and T2 are two very large binary trees. Create an algorithm to determine if T2 is a subtree of T1.

// A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n is identical to T2. That is, if you cut off the tree at node n, the two trees would be identical.

// Note: This problem is slightly different from the original problem.
// Input: t1 = [1, 2, 3], t2 = [2]
// Output: true


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool check_equal(TreeNode * t1, TreeNode* t2){  // check whether the tree t1 and t2 are equal.
        bool is_self_equal;
        bool is_left_equal;
        bool is_right_equal;
        if (t1 != NULL && t2 != NULL){
            is_self_equal = t1->val == t2->val;
            is_left_equal = check_equal(t1->left, t2->left);   // check whether its left child is equal
            is_right_equal = check_equal(t1->right, t2->right); // check whether its right child is equal
            return (is_self_equal && is_left_equal && is_right_equal);
        }else{
            if (t2 == NULL){
                return true;
            }
            return false;
        }
    }

    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) return false;         // base situation
        if (check_equal(t1, t2)) return true;
        else{
            return (checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2));
        }
    }
};
