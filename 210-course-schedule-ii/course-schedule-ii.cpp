class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> adj(numCourses);
        int n = prerequisites.size();
        vector<int> INdegree(numCourses);

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

        if(q.empty()) return ans;
        int count=0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            count++;

            for(auto it:adj[node]){
                INdegree[it]--;
                if(INdegree[it]==0) q.push(it);
            }
        }

        if(count==numCourses) return ans;

        return {};
    }
};