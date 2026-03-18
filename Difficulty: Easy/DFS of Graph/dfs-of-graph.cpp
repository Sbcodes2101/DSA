class Solution {
  public:
    void dfs(vector<int> &ans,vector<int> &visited,vector<vector<int>>& adj,int node){
        visited[node] = 1;
        ans.push_back(node);
            
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(ans,visited,adj,it);
            }
        }
        
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> ans;
        vector<int> visited(n,0);
        dfs(ans,visited,adj,0);
        return ans;
    }
};