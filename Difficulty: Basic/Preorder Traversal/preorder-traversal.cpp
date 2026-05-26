/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void f(vector<int> &ans,Node* root){
        if(root==NULL) return;
        
        ans.push_back(root->data);
        f(ans,root->left);
        f(ans,root->right);
        
        return;
    }
    
    vector<int> preOrder(Node* root) {
        // code here
        vector<int> ans;
        f(ans,root);
        return ans;
    }
};