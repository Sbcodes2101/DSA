class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int cs = intervals[0][0];
        int ce = intervals[0][1];
        int n = intervals.size();

        for(int i=1;i<n;i++){
            if(ce<intervals[i][0]){
                ans.push_back({cs,ce});
                cs = intervals[i][0];
                ce = intervals[i][1];
            }

            else{
                ce = max(ce,intervals[i][1]);
            }
        }

        ans.push_back({cs,ce});

        return ans;
    }
};