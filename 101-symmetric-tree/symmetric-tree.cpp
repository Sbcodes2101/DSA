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
    bool check(TreeNode* lft,TreeNode* rght){
        if(lft == NULL && rght == NULL) return true;
        if(lft == NULL || rght == NULL) return false;

        if(lft->val == rght->val && check(lft->right,rght->left) && check(lft->left,rght->right)) return true;

        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return check(root->left,root->right);
    }
};