/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void f(vector<int> &ans,Node* root){
        if(root==NULL) return;
        
        f(ans,root->left);
        ans.push_back(root->data);
        f(ans,root->right);
        
        return;
    }
    
    vector<int> inOrder(Node* root) {
        // code here
        vector<int> ans;
        f(ans,root);
        return ans;
    }
};