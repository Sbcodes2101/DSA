class Solution {
public:
    bool dfs(unordered_map<int,vector<int>> &mp,vector<bool> &visited,int u,int v){
        visited[u] = true;

        if(u==v) return true;

        for(auto it:mp[u]){
            if(!visited[it]){
               if(dfs(mp,visited,it,v)){
                return true;
               }
            }
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            vector<bool> visited(n,false);
            if(mp.find(u)!=mp.end() && mp.find(v)!=mp.end() && dfs(mp,visited,u,v)){
                return edges[i];
            }
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        return ans;
    }
};