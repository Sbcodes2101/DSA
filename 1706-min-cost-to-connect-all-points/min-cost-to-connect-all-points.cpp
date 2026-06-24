class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x2-x1)+abs(y2-y1);

                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }

        priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> p;
        vector<bool> isMST(n,false);
        vector<int> parent(n);
        p.push({0,{0,-1}});
        int count=0;

        while(!p.empty()){
            int wght = p.top().first;
            int node = p.top().second.first;
            int prnt = p.top().second.first;
            p.pop();

            if(!isMST[node]){
                isMST[node] = true;
                count += wght;
                parent[node] = prnt;

                for(auto it:adj[node]){
                    int neighbour = it.first;
                    int weight = it.second;

                    if(!isMST[neighbour]){
                        p.push({weight,{neighbour,node}});
                    }
                }
            }
        }
        return count;
    }
};