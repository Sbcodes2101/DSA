class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        vector<int> ans;
        queue<int> q;
        q.push(0);
        vector<bool> visited(n,false);
        visited[0] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it:adj[node]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        
        return ans;
    }
};