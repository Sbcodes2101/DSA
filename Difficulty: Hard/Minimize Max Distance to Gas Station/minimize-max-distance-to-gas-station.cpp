class Solution {
public:
    
    double minMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        vector<int> howMany(n-1,0);
        priority_queue<pair<long double, int>> pq;
        
        if(n <= 1) return 0;
        
        for(int i=0;i<n-1;i++){
            pq.push({stations[i+1]-stations[i] , i});
        }
        
        for(int gas = 1; gas <= k; gas++){
            auto tp = pq.top();
            pq.pop();
            int secInd = tp.second;
            howMany[secInd]++;
            long double iniDiff = stations[secInd+1]-stations[secInd];
            long double newSecLen = iniDiff/(howMany[secInd]+1);
            pq.push({newSecLen, secInd});
        }
        return pq.top().first;
    }
};