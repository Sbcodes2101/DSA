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
    // int f(TreeNode* root){
    //     if(root==NULL) return 0;

    //     int lft_hght = f(root->left);
    //     int rght_hght = f(root->right);

    //     return 1+max(lft_hght,rght_hght);
    // }

    int f(TreeNode* root,int &maxi){
        if(root==NULL) return 0;

        int lft_hght = f(root->left,maxi);
        int rght_hght = f(root->right,maxi);

        maxi = max(maxi,lft_hght+rght_hght);

        return 1+max(lft_hght,rght_hght);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // if(root==NULL) return 0;

        // int lft_hght = f(root->left);
        // int rght_hght = f(root->right);

        // int curr_diameter = lft_hght + rght_hght;

        // int lft = diameterOfBinaryTree(root->left);
        // int rght = diameterOfBinaryTree(root->right);

        // return max(curr_diameter,max(lft,rght));

        // O(n) solution
        if(root==NULL) return 0;
        int maxi=INT_MIN;
        f(root,maxi);
        return maxi;
    }
};