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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        bool flag = true;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);

            if(flag){
                for(int i=0;i<size;i++){
                    TreeNode* node = q.front();
                    q.pop();

                    if(node->left!=NULL) q.push(node->left);
                    if(node->right!=NULL) q.push(node->right);

                    level[i] = node->val;
                }
                flag=false;
            }

            else{
                for(int i=size-1;i>=0;i--){
                    TreeNode* node = q.front();
                    q.pop();

                    if(node->left!=NULL) q.push(node->left);
                    if(node->right!=NULL) q.push(node->right);

                    level[i] = node->val;
                }
                flag=true;
            }
            ans.push_back(level);
        }
        return ans;
    }
};