class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int ans = 0;
        int cs = intervals[0][0];
        int ce = intervals[0][1];

        for(int i=1;i<n;i++){
            int ns = intervals[i][0];
            int ne = intervals[i][1];

            if(ce>ns){ //overlap
                ans++;
                ce = min(ce,ne);
            }
            else{
                ce = ne;
            }
        }

        return ans;
    }
};