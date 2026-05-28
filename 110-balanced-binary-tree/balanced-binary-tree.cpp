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
    int height(TreeNode* root){
        if(root==NULL) return 0;
        
        int lft = 1+height(root->left);
        int rght = 1+height(root->right);

        return max(lft,rght);
    }

    bool f(TreeNode* root){
        if(root == NULL) return true;

        int left_hght = height(root->left);
        int right_hght = height(root->right);

        if(abs(left_hght-right_hght) > 1) return false;

        bool lft = f(root->left);
        bool rght = f(root->right);

        if(!lft || !rght) return false;

        return true;
    }

    bool isBalanced(TreeNode* root) {
        return f(root);
    }
};