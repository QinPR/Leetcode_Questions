// 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
// 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// 输出: [3,9,20,null,null,15,7]

// 来自MRarity的思路：
// preorder第一个元素为root，在inorder里面找到root，在它之前的为左子树（长l1），之后为右子树（长l2）。preorder[1]到preorder[l1]为左子树,之后为右子树，分别递归。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool head = true;
    TreeNode * head_node = new TreeNode();
    int find_root(int root, vector<int>& inorder){
        for (int i = 0; i < inorder.size(); ++i){
            if (root == inorder[i]) return i;
        }
        return -1;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, TreeNode* node = NULL){
        int root = preorder[0];
        preorder.erase(preorder.begin());
        if (inorder.size() <= 1){ // means there are no child anymore
            if (head){
                head_node->val = -1;
                return head_node;
            }
            node->val = root;
            return NULL;
        }
        int root_in_inorder = find_root(root, inorder);
        bool no_left = (root_in_inorder == 0);
        bool no_right = (root_in_inorder == inorder.size()-1);
        if (head){
            head = false;
            node = head_node;
        }
        node->val = root;   // assign the value to the node
        if (!no_left){
            vector<int>::const_iterator First = inorder.begin();
            vector<int>::const_iterator Second = inorder.begin() + root_in_inorder;
            vector<int> new_left_inorder(First, Second);
            TreeNode * left = new TreeNode();
            node->left = left;
            buildTree(preorder, new_left_inorder, left);
        }
        if (!no_right){
            vector<int>::const_iterator Third = inorder.begin() + root_in_inorder+1;
            vector<int>::const_iterator Fourth = inorder.end();
            vector<int> new_right_inorder(Third, Fourth);
            TreeNode * right = new TreeNode();
            node->right = right;
            buildTree(preorder, new_right_inorder, right);
        }
        return node;
    }
};
