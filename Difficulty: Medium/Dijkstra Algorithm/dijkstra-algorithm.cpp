class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<bool> Explored(V,0);
        vector<vector<pair<int,int>>> adj(V);
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int> dist(V,INT_MAX);
        dist[src] = 0;
        
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> p;
        
        p.push({0,src});
        
        while(!p.empty()){
            int node = p.top().second;
            p.pop();
            
            if(Explored[node] == 1) continue;
            
            Explored[node] = 1;
            
            for(auto it:adj[node]){
                int neighbour = it.first;
                int weight = it.second;
                
                if(!Explored[neighbour] && dist[neighbour]>dist[node]+weight){
                    dist[neighbour]=dist[node]+weight;
                    p.push({dist[neighbour],neighbour});
                }
            }
        }
        
        return dist;
    }
};