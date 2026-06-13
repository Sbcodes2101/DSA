class Solution {
  public:
    void dfs(vector<vector<int>>& adj,vector<int> &ans,vector<bool> &visited,int node){
        visited[node] = true;
        ans.push_back(node);
        
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(adj,ans,visited,it);
            }
        }
        
        return;
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> ans;
        vector<bool> visited(n,false);
        dfs(adj,ans,visited,0);
        return ans;
    }
};