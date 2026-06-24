class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        int cost=0;
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> p;
        vector<bool> isMST(V,0);
        vector<int> parent(V);
        
        p.push({0,{0,-1}});
        
        while(!p.empty()){
            int wt = p.top().first;
            int node = p.top().second.first;
            int prnt = p.top().second.second;
            p.pop();
            
            if(!isMST[node]){
                isMST[node] = true;
                cost += wt;
                parent[node] = prnt;
                
                for(auto it:adj[node]){
                    int neighbour = it.first;
                    int wght=it.second;
                    if(!isMST[neighbour]){
                        p.push({wght,{neighbour,node}});
                    }
                }
            }
        }
        return cost;
    }
};