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
    TreeNode* build(vector<int> &inorder,vector<int> &postorder,int infirst,int inlast,int idx,unordered_map<int,int> &mp){
        if(infirst>inlast) return NULL;
        TreeNode* root = new TreeNode(postorder[idx]);
        int pos = -1;

        if(mp.find(postorder[idx])!=mp.end()){
            pos = mp[postorder[idx]];
        }

        int size = inlast-pos+1;

        root->right = build(inorder, postorder,pos+1,inlast,idx-1,mp);
        root->left = build(inorder,postorder,infirst,pos-1,idx-size,mp);

        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }

        return build(inorder, postorder, 0, n-1, n-1,mp);

    }
};