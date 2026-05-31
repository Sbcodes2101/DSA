/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool isleaf(Node* root){
        return (root->left == NULL && root->right == NULL);
    }
    
    void lboundary(Node* root, vector<int>& ans) {
    if(root == NULL || isleaf(root)) return;

    ans.push_back(root->data);

    if(root->left)
        lboundary(root->left, ans);
    else
        lboundary(root->right, ans);
    }
    
    
    void addleaf(Node *root,vector<int> &ans){
        if(root == NULL) return;
        if(isleaf(root)){
            ans.push_back(root->data);
            return;
        }
        
        addleaf(root->left,ans);
        addleaf(root->right,ans);
        
        return;
    }
    
    void rboundary(Node* root, vector<int>& ans) {
    if(root == NULL || isleaf(root)) return;

    if(root->right)
        rboundary(root->right, ans);
    else
        rboundary(root->left, ans);

    ans.push_back(root->data);
    }
    
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(root==NULL) return ans;
        if(!isleaf(root)) ans.push_back(root->data);
        lboundary(root->left,ans);
        addleaf(root,ans);
        rboundary(root->right,ans);
        return ans;
    }
};