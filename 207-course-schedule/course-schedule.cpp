class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int n = prerequisites.size();
        vector<int> INdegree(numCourses,0);

        for(int i=0;i<n;i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
            INdegree[u]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(INdegree[i]==0) q.push(i);
        }

        if(q.empty()) return false;
        int count = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            for(auto it:adj[node]){
                INdegree[it]--;
                if(INdegree[it]==0) q.push(it);
            }
        }

        return (count==numCourses);
    }
};