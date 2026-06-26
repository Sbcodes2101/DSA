class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dis(n,INT_MAX);
        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            adj[u].push_back({v,wt});
        }

        dis[src] = 0;
        queue<pair<int,pair<int,int>>> p;
        p.push({0,{src,0}});

        while(!p.empty()){
            int steps = p.front().first;
            int node = p.front().second.first;
            int cost = p.front().second.second;
            p.pop();

            if(steps>k) continue;

            for(auto it:adj[node]){
                int neighbour = it.first;
                int wght = it.second;

                if(dis[neighbour]>cost+wght){
                    dis[neighbour] = cost+wght;
                    p.push({steps+1,{neighbour,dis[neighbour]}});
                }
            }
        }

        return (dis[dst]==INT_MAX)? -1:dis[dst];
    }
};