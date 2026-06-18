class Solution {
  public:
    
    void dfs(vector<vector<int>> &adj,vector<int> &visited,int node,vector<int> &ans){
        ans.push_back(node);
        visited[node] = 1;
        
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(adj,visited,it,ans);
            }
        }
    }
    
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> ans;
        vector<vector<int>> adj(V);
        vector<int> visited(V,0);
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                 vector<int> ans1;
                 dfs(adj,visited,i,ans1);
                 ans.push_back(ans1);
            }
        }
        
        return ans;
    }
};
